/*
 *      Wonderful routine to create a Z88 application
 *
 *      z88app [binary file] [startup file] [-nt]
 *
 *      djm 2/4/99 - A very, very quick knock up!
 *
 *      Application ID number is generated from time()
 *      - if you have a better automatic algorithm let me know!
 *
 *      djm 12/4/99
 *      Thanks Dennis! The ROM header was being generated two bytes
 *      lower than it should've been..ooops, and oops again!
 *
 *      djm 26/4/99
 *      Implemented some other changes suggested by Dennis, we now
 *      change the suffix for output files, hence default output
 *      will be a.63, a.62 etc
 *      Also added some condition Win/Dos stuff
 *
 *      djm 28/4/99
 *      If zorg != page boundary then we save only from zorg upwards  
 *      (request from DG)
 * 
 *      dg 17/5/99
 *      Changes to make more MSDOS friendly
 *
 *        djm 12/1/2000
 *        Add option to disallow page truncation
 *      
 *      $Id: z88.c,v 1.9 2016-07-01 20:34:45 dom Exp $
 */


#include "appmake.h"


#define MAX_ADDR        65472


struct romheader {

/* Front DOR */
    char parent[3];
    char brother[3];
    char son[3];
    char dortype;
    char dorlen;
    char key;
    char namelen;
    char name[5];
    char termin;

    char spacer[37];

/* Card header */
    char cardid[4];
    char cardsize;
    char subtype;
    char header[2];
};

/*
 * Default stuff at the top of the DOR, this is 10 bytes long
 */

static unsigned char appldef[]={ 19, 8 , 'N', 5 , 'A','P','P','L',0,255 };


static char             *binname      = NULL;
static char             *crtfile      = NULL;
static char             *outfile      = NULL;
static char              do_truncate  = 0;
static char              help         = 0;

static unsigned char    *memory;      /* Pointer to Z80 memory */
static long              zorg;        /* Origin of compiler program */

/* Options that are available for this module */
option_t z88_options[] = {
    { 'h', "help",     "Display this help",          OPT_BOOL,  &help},
    { 'b', "binfile",  "Linked binary file",         OPT_STR,   &binname },
    { 'c', "crt0file", "crt0 file used in linking",  OPT_STR,   &crtfile },
    { 'o', "output",   "Name of output file",        OPT_STR,   &outfile },
    {  0 , "nt",       "Do not do_truncate bank 63",    OPT_BOOL,  &do_truncate },
    {  0,  NULL,       NULL,                         OPT_NONE,  NULL }
};



/* Prototypes for our functions */
static void SaveBlock(unsigned offset, char *base, char *ext);


/*
 * Execution starts here
 */

int z88_exec(char *target)
{
    int     pages;          /* size of card in banks */
    long     indor;          /* address of app dor */
    long     in_dor_seg_setup;      /* address of seg bindings */
    long     in_dor_reqpag;
    long     in_dor_safedata;
    long     application_dor_entrypoint;
    FILE    *binfile;        /* Read in bin file */
    long    filesize;
    struct romheader *hdr;  /* Pointer to ROM DOR */
    int     appdorpg;       /* Page where app DOR is */
    int     appdoroff;      /* Offset of where the app DOR is */
    int        readlen;        /* Amount read in */
    time_t  cardidno;       /* Card ID number - construct randomly */
    int     reqpag = 0;
    int     safedata = 0;


    if ( help )
        return -1;

    if ( binname == NULL || crtfile == NULL ) {
        return -1;
    }

#ifdef MSDOS
    if ( do_truncate ) {
        fputs("-nt option not supported under MSDOS..continuing\n",stderr);
    }
#endif



    if ( outfile == NULL )
        outfile = binname;


    zorg = get_org_addr(crtfile);
    if ( zorg == -1 ) 
        myexit("Could not find parameter ZORG (compiled as BASIC?)\n",1);
    indor = parameter_search(crtfile,".map","in_dor");
    if ( indor == -1 ) 
        myexit("Could not find parameter in_dor - no app dor present\n",1);
    in_dor_seg_setup = parameter_search(crtfile,".map","in_dor_seg_setup");
    if ( in_dor_seg_setup == -1 ) 
        myexit("Could not find parameter in_dor_seg_setup - no app dor present\n",1);


    application_dor_entrypoint = parameter_search(crtfile,".map","application_dor_entrypoint");
    if ( application_dor_entrypoint == -1 ) 
        myexit("Could not find parameter application_dor_entrypoint- no app dor present\n",1);
    in_dor_reqpag = parameter_search(crtfile,".map","in_dor_reqpag");
    if ( in_dor_reqpag == -1 ) 
        myexit("Could not find parameter in_dor_reqpag - no app dor present\n",1);
    in_dor_safedata = parameter_search(crtfile,".map","in_dor_safedata");
    if ( in_dor_safedata == -1 ) 
        myexit("Could not find parameter in_dor_safedata - no app dor present\n",1);
    reqpag = parameter_search(crtfile,".map","reqpag");
    if ( reqpag == -1 )  {
         int asmtail = parameter_search(crtfile,".map","ASMTAIL_bss_tail");
         if ( asmtail == -1 ) {
              myexit("reqpag isn't defined and can't find the end of the BSS segment\n",1);
         }
         reqpag = 0;
         if ( asmtail > 0x2000 ) {
             reqpag = ((asmtail - 0x2000) / 256) + 1;
         }
         printf("Application will use %d pages of bad memory\n",reqpag);
    }


    pages = ( (65536L - (long)(zorg+1))/16384L);
    pages++;
    if      (pages == 4 ) {
        fputs("Four segments needed for this program - you may have some problems\n",stderr);
        fputs("running this beast - try and cut it down a little bit!!\n",stderr);
    }

/*
 * Allocate some memory
 */

    if ( do_truncate == FALSE ) {
        memory=calloc(1,(unsigned)(65536L-zorg));
    } else {
        memory = calloc(1,65536L);
    }
    if (memory == NULL)
        myexit("Can't allocate memory\n",1);

    if ( (binfile = fopen_bin(binname, crtfile) ) == NULL ) {
        myexit("Can't open binary file\n",1);
    }

    if ( fseek(binfile, 0, SEEK_END) ) {
        fclose(binfile);
        myexit("Couldn't determine the size of the file\n",1);
    }

    filesize = ftell(binfile);
    if ( filesize > 65536L ) {
        fclose(binfile);
        myexit("The source binary is over 65,536 bytes in length.\n",1);
    }

    fseek(binfile, 0, SEEK_SET);

    /* Check to see if we will infringe on the ROM header, if not then load it in */
    if ( zorg + filesize <= MAX_ADDR ) {
        if ( do_truncate == FALSE ) 
            readlen = fread(memory,1,filesize,binfile);
        else 
            readlen = fread(memory+zorg,1,filesize,binfile);

        if ( filesize != readlen ) {
            fclose(binfile);
            myexit("Couldn't read in binary file\n",1);
        }
    } else {
        fclose(binfile);
        myexit("Binary file too large! Change the org!\n",1);
    }
    fclose(binfile);

    if ( do_truncate ) 
        zorg = 0;



    /*  We've read it in, so now construct the ROM header */
    hdr = (struct romheader *)(memory+MAX_ADDR-zorg);


    /*
     * Try to create some sort of unique card id number so we don't clash
     * violently with other apps, we'll use time() which returns the time
     * since a base - different for different OS, but hopefully consistent
     * with different flavours of the OS
     */

    cardidno=time(NULL);

    hdr->cardid[0]=(cardidno%256)&127;
    hdr->cardid[1]=(cardidno/256)&127;
    hdr->cardid[2]=(cardidno%65536)&127;
    hdr->cardid[3]=(cardidno/65336)|128;

    hdr->cardsize=(char )pages;
    hdr->subtype=0;
    hdr->header[0]='O';
    hdr->header[1]='Z';
    memcpy(&hdr->dortype,appldef,10);
    /* Now, deal with the dor address */
    appdorpg = 63- ( (65536L - (long)(indor+1))/16384L);
    appdoroff= indor&16383;
    hdr->son[0]=appdoroff%256;
    hdr->son[1]=appdoroff/256;
    hdr->son[2]=appdorpg;

    /* Now, set up the needed pages in the app DOR */
    switch(pages) {
    case 4:
        *(memory+in_dor_seg_setup-zorg)=(char)60;
    case 3:
        *(memory+in_dor_seg_setup-zorg+1)=(char)61;
    case 2:
        *(memory+in_dor_seg_setup-zorg+2)=(char)62;
    case 1:
        *(memory+in_dor_seg_setup-zorg+3)=(char)63;
    }

    *(memory + in_dor_reqpag - zorg) = reqpag ? (reqpag < 32 ? 32 : reqpag) : 0;
    *(memory + in_dor_safedata - zorg) = safedata ? (safedata + 100) % 256 : 100;
    *(memory + in_dor_safedata - zorg + 1) = safedata ? (safedata + 55) / 256 : 0;

    /* Now we need to setup the enquire_entry point */
    if ( reqpag == 0 || reqpag > 32 ) {
        *(memory + application_dor_entrypoint - zorg + 3 ) = 0x37;  /* scf */
        *(memory + application_dor_entrypoint - zorg + 4 ) = 0xc9;  /* ret */
    } else {
        /* ld bc, start, ld bc, end, and a, ret */
        *(memory + application_dor_entrypoint - zorg + 3 ) = 0x01;  /* ld bc,nnnn */
        *(memory + application_dor_entrypoint - zorg + 4 ) = (8192 + reqpag) % 256; 
        *(memory + application_dor_entrypoint - zorg + 5 ) = (8192 + reqpag) / 256; 
        *(memory + application_dor_entrypoint - zorg + 6 ) = 0x11;  /* ld de,nnnn nnnn=16384*/
        *(memory + application_dor_entrypoint - zorg + 7 ) = 0x00;  
        *(memory + application_dor_entrypoint - zorg + 8 ) = 0x40;  
        *(memory + application_dor_entrypoint - zorg + 9 ) = 0xa7; /* and a */  
        *(memory + application_dor_entrypoint - zorg + 10 ) = 0xc9;  /* ret */
    }

    /* Okay, now thats done, we have to save the image as banks.. */
    if ( pages == 4 ) 
        SaveBlock(0,outfile,".60");
    if  ( pages >= 3 ) 
        SaveBlock(16384,outfile,".61");
    if ( pages >= 2 ) 
        SaveBlock(32768,outfile,".62");
    SaveBlock(49152,outfile,".63");

    return 0;
}

static void SaveBlock(unsigned offset, char *base, char *ext)
{
    char    name[FILENAME_MAX+1];
    char    buffer[LINEMAX+1];
    int     length;
    FILE    *fp;

    strcpy(name,base);
    suffix_change(name,ext);

    if ( ( fp = fopen(name,"wb") ) == NULL ) {
        sprintf(buffer,"Can't open output file %s\n",name);
        myexit(buffer,1);
    }
    if ( (zorg-offset) < 16384 && do_truncate == FALSE  ) {
        /* Saving the segment in which the code is org'd to */
        length = 16384-(zorg-offset);
    } else { 
        length = 16384;
    }

    if (fwrite(memory+offset-zorg+16384-length,1,length,fp) != length ) {
        sprintf(buffer,"Can't write to  output file %s\n",name);
        myexit(buffer,1);
    }
    fclose(fp);
}


