


#ifndef _ADT_WA_STACK_H
#define _ADT_WA_STACK_H

#include <stddef.h>

// DATA STRUCTURES

typedef struct wa_stack_s
{

   void       *data;
   size_t      size;
   size_t      capacity;

} wa_stack_t;

extern size_t __LIB__ __FASTCALL__ wa_stack_capacity(wa_stack_t *s);


extern void __LIB__ __FASTCALL__ wa_stack_clear(wa_stack_t *s);


extern void __LIB__ __FASTCALL__ wa_stack_destroy(wa_stack_t *s);


extern int __LIB__ __FASTCALL__ wa_stack_empty(wa_stack_t *s);


extern wa_stack_t __LIB__ *wa_stack_init(void *p,void *data,size_t capacity);
extern wa_stack_t __LIB__ __CALLEE__ *wa_stack_init_callee(void *p,void *data,size_t capacity);
#define wa_stack_init(a,b,c) wa_stack_init_callee(a,b,c)


extern void __LIB__ __FASTCALL__ *wa_stack_pop(wa_stack_t *s);


extern int __LIB__ wa_stack_push(wa_stack_t *s,void *item);
extern int __LIB__ __CALLEE__ wa_stack_push_callee(wa_stack_t *s,void *item);
#define wa_stack_push(a,b) wa_stack_push_callee(a,b)


extern size_t __LIB__ __FASTCALL__ wa_stack_size(wa_stack_t *s);


extern void __LIB__ __FASTCALL__ *wa_stack_top(wa_stack_t *s);



#endif