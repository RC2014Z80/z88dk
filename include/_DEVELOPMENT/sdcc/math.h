


#ifndef _MATH_H
#define _MATH_H

// THE SELECTED FLOATING POINT PACKAGE MAY NOT SUPPORT ALL LISTED FUNCTIONS

#ifndef _FLOAT_T_DEFINED
#define _FLOAT_T_DEFINED

   #ifdef __SDCC
   
   typedef float float_t;
   
   #else
   
   typedef double float_t;
   
   #endif
   
#endif

#ifndef _DOUBLE_T_DEFINED
#define _DOUBLE_T_DEFINED

   #ifdef __SDCC
   
   typedef float double_t;
   
   #else
   
   typedef double double_t;
   
   #endif
   
#endif

#define FLT_EVAL_METHOD        1
#define MATH_ERRNO             1
#define MATH_ERREXCEPT         2
#define math_errhandling       1

#ifdef __SDCC

#define HUGE_VAL               1.7014117331E+38
#define HUGE_VALF              1.7014117331E+38
#define INFINITY               1.7014117331E+38

#else

#define HUGE_VAL               1.7014118346E+38
#define HUGE_VALF              1.7014118346E+38
#define INFINITY               1.7014118346E+38

#endif

extern double_t acos(double_t x);
extern double_t acos_fastcall(double_t x) __z88dk_fastcall;
#define acos(a) acos_fastcall(a)


extern double_t asin(double_t x);
extern double_t asin_fastcall(double_t x) __z88dk_fastcall;
#define asin(a) asin_fastcall(a)


extern double_t atan(double_t x);
extern double_t atan_fastcall(double_t x) __z88dk_fastcall;
#define atan(a) atan_fastcall(a)


extern double_t atan2(double_t y,double_t x);
extern double_t atan2_callee(double_t y,double_t x) __z88dk_callee;
#define atan2(a,b) atan2_callee(a,b)



extern double_t cos(double_t x);
extern double_t cos_fastcall(double_t x) __z88dk_fastcall;
#define cos(a) cos_fastcall(a)


extern double_t sin(double_t x);
extern double_t sin_fastcall(double_t x) __z88dk_fastcall;
#define sin(a) sin_fastcall(a)


extern double_t tan(double_t x);
extern double_t tan_fastcall(double_t x) __z88dk_fastcall;
#define tan(a) tan_fastcall(a)



extern double_t acosh(double_t x);
extern double_t acosh_fastcall(double_t x) __z88dk_fastcall;
#define acosh(a) acosh_fastcall(a)


extern double_t asinh(double_t x);
extern double_t asinh_fastcall(double_t x) __z88dk_fastcall;
#define asinh(a) asinh_fastcall(a)


extern double_t atanh(double_t x);
extern double_t atanh_fastcall(double_t x) __z88dk_fastcall;
#define atanh(a) atanh_fastcall(a)



extern double_t cosh(double_t x);
extern double_t cosh_fastcall(double_t x) __z88dk_fastcall;
#define cosh(a) cosh_fastcall(a)


extern double_t sinh(double_t x);
extern double_t sinh_fastcall(double_t x) __z88dk_fastcall;
#define sinh(a) sinh_fastcall(a)


extern double_t tanh(double_t x);
extern double_t tanh_fastcall(double_t x) __z88dk_fastcall;
#define tanh(a) tanh_fastcall(a)



extern double_t exp(double_t x);
extern double_t exp_fastcall(double_t x) __z88dk_fastcall;
#define exp(a) exp_fastcall(a)


extern double_t exp2(double_t x);
extern double_t exp2_fastcall(double_t x) __z88dk_fastcall;
#define exp2(a) exp2_fastcall(a)


extern double_t expm1(double_t x);
extern double_t expm1_fastcall(double_t x) __z88dk_fastcall;
#define expm1(a) expm1_fastcall(a)


extern double_t frexp(double_t value,int *exp);
extern double_t frexp_callee(double_t value,int *exp) __z88dk_callee;
#define frexp(a,b) frexp_callee(a,b)


extern int ilogb(double_t x);
extern int ilogb_fastcall(double_t x) __z88dk_fastcall;
#define ilogb(a) ilogb_fastcall(a)


extern double_t ldexp(double_t x,int exp);
extern double_t ldexp_callee(double_t x,int exp) __z88dk_callee;
#define ldexp(a,b) ldexp_callee(a,b)



extern double_t log(double_t x);
extern double_t log_fastcall(double_t x) __z88dk_fastcall;
#define log(a) log_fastcall(a)


extern double_t log10(double_t x);
extern double_t log10_fastcall(double_t x) __z88dk_fastcall;
#define log10(a) log10_fastcall(a)


extern double_t log1p(double_t x);
extern double_t log1p_fastcall(double_t x) __z88dk_fastcall;
#define log1p(a) log1p_fastcall(a)


extern double_t log2(double_t x);
extern double_t log2_fastcall(double_t x) __z88dk_fastcall;
#define log2(a) log2_fastcall(a)


extern double_t logb(double_t x);
extern double_t logb_fastcall(double_t x) __z88dk_fastcall;
#define logb(a) logb_fastcall(a)



extern double_t scalbn(double_t x,int n);
extern double_t scalbn_callee(double_t x,int n) __z88dk_callee;
#define scalbn(a,b) scalbn_callee(a,b)


extern double_t scalbln(double_t x,int n);
extern double_t scalbln_callee(double_t x,int n) __z88dk_callee;
#define scalbln(a,b) scalbln_callee(a,b)



extern double_t fabs(double_t x);
extern double_t fabs_fastcall(double_t x) __z88dk_fastcall;
#define fabs(a) fabs_fastcall(a)


extern double_t hypot(double_t x,double_t y);
extern double_t hypot_callee(double_t x,double_t y) __z88dk_callee;
#define hypot(a,b) hypot_callee(a,b)



extern double_t pow(double_t x,double_t y);
extern double_t pow_callee(double_t x,double_t y) __z88dk_callee;
#define pow(a,b) pow_callee(a,b)


extern double_t sqrt(double_t x);
extern double_t sqrt_fastcall(double_t x) __z88dk_fastcall;
#define sqrt(a) sqrt_fastcall(a)


extern double_t cbrt(double_t x);
extern double_t cbrt_fastcall(double_t x) __z88dk_fastcall;
#define cbrt(a) cbrt_fastcall(a)



extern double_t erf(double_t x);
extern double_t erf_fastcall(double_t x) __z88dk_fastcall;
#define erf(a) erf_fastcall(a)


extern double_t erfc(double_t x);
extern double_t erfc_fastcall(double_t x) __z88dk_fastcall;
#define erfc(a) erfc_fastcall(a)


extern double_t lgamma(double_t x);
extern double_t lgamma_fastcall(double_t x) __z88dk_fastcall;
#define lgamma(a) lgamma_fastcall(a)


extern double_t tgamma(double_t x);
extern double_t tgamma_fastcall(double_t x) __z88dk_fastcall;
#define tgamma(a) tgamma_fastcall(a)



extern double_t ceil(double_t x);
extern double_t ceil_fastcall(double_t x) __z88dk_fastcall;
#define ceil(a) ceil_fastcall(a)


extern double_t floor(double_t x);
extern double_t floor_fastcall(double_t x) __z88dk_fastcall;
#define floor(a) floor_fastcall(a)


extern double_t nearbyint(double_t x);
extern double_t nearbyint_fastcall(double_t x) __z88dk_fastcall;
#define nearbyint(a) nearbyint_fastcall(a)


extern double_t rint(double_t x);
extern double_t rint_fastcall(double_t x) __z88dk_fastcall;
#define rint(a) rint_fastcall(a)


extern long lrint(double_t x);
extern long lrint_fastcall(double_t x) __z88dk_fastcall;
#define lrint(a) lrint_fastcall(a)


extern double_t round(double_t x);
extern double_t round_fastcall(double_t x) __z88dk_fastcall;
#define round(a) round_fastcall(a)


extern long lround(double_t x);
extern long lround_fastcall(double_t x) __z88dk_fastcall;
#define lround(a) lround_fastcall(a)


extern double_t trunc(double_t x);
extern double_t trunc_fastcall(double_t x) __z88dk_fastcall;
#define trunc(a) trunc_fastcall(a)



extern double_t modf(double_t value,double_t *iptr);
extern double_t modf_callee(double_t value,double_t *iptr) __z88dk_callee;
#define modf(a,b) modf_callee(a,b)


extern double_t fmod(double_t x,double_t y);
extern double_t fmod_callee(double_t x,double_t y) __z88dk_callee;
#define fmod(a,b) fmod_callee(a,b)


extern double_t remainder(double_t x,double_t y);
extern double_t remainder_callee(double_t x,double_t y) __z88dk_callee;
#define remainder(a,b) remainder_callee(a,b)


extern double_t remquo(double_t x,double_t y,int *quo);
extern double_t remquo_callee(double_t x,double_t y,int *quo) __z88dk_callee;
#define remquo(a,b,c) remquo_callee(a,b,c)



extern double_t copysign(double_t x,double_t y);
extern double_t copysign_callee(double_t x,double_t y) __z88dk_callee;
#define copysign(a,b) copysign_callee(a,b)


extern double_t nan(const char *tagp);
extern double_t nan_fastcall(const char *tagp) __z88dk_fastcall;
#define nan(a) nan_fastcall(a)



extern double_t nextafter(double_t x,double_t y);
extern double_t nextafter_callee(double_t x,double_t y) __z88dk_callee;
#define nextafter(a,b) nextafter_callee(a,b)


extern double_t nexttoward(double_t x,double_t y);
extern double_t nexttoward_callee(double_t x,double_t y) __z88dk_callee;
#define nexttoward(a,b) nexttoward_callee(a,b)



extern double_t fdim(double_t x,double_t y);
extern double_t fdim_callee(double_t x,double_t y) __z88dk_callee;
#define fdim(a,b) fdim_callee(a,b)



extern double_t fmax(double_t x,double_t y);
extern double_t fmax_callee(double_t x,double_t y) __z88dk_callee;
#define fmax(a,b) fmax_callee(a,b)


extern double_t fmin(double_t x,double_t y);
extern double_t fmin_callee(double_t x,double_t y) __z88dk_callee;
#define fmin(a,b) fmin_callee(a,b)



extern double_t fma(double_t x,double_t y,double_t z);
extern double_t fma_callee(double_t x,double_t y,double_t z) __z88dk_callee;
#define fma(a,b,c) fma_callee(a,b,c)



extern int isgreater(double_t x,double_t y);
extern int isgreater_callee(double_t x,double_t y) __z88dk_callee;
#define isgreater(a,b) isgreater_callee(a,b)


extern int isgreaterequal(double_t x,double_t y);
extern int isgreaterequal_callee(double_t x,double_t y) __z88dk_callee;
#define isgreaterequal(a,b) isgreaterequal_callee(a,b)


extern int isless(double_t x,double_t y);
extern int isless_callee(double_t x,double_t y) __z88dk_callee;
#define isless(a,b) isless_callee(a,b)


extern int islessequal(double_t x,double_t y);
extern int islessequal_callee(double_t x,double_t y) __z88dk_callee;
#define islessequal(a,b) islessequal_callee(a,b)


extern int islessgreater(double_t x,double_t y);
extern int islessgreater_callee(double_t x,double_t y) __z88dk_callee;
#define islessgreater(a,b) islessgreater_callee(a,b)


extern int isunordered(double_t x,double_t y);
extern int isunordered_callee(double_t x,double_t y) __z88dk_callee;
#define isunordered(a,b) isunordered_callee(a,b)



// NO DISTINCTION BETWEEN FLOAT AND DOUBLE

#define acosf        acos
#define asinf        asin
#define atanf        atan
#define atan2f       atan2

#define cosf         cos
#define sinf         sin
#define tanf         tan

#define acoshf       acosh
#define asinhf       asinh
#define atanhf       atanh

#define coshf        cosh
#define sinhf        sinh
#define tanhf        tanh

#define expf         exp
#define exp2f        exp2
#define expm1f       expm1
#define frexpf       frexp
#define ilogbf       ilogb
#define ldexpf       ldexp

#define logf         log
#define log10f       log10
#define log1pf       log1p
#define log2f        log2
#define logbf        logb

#define scalbnf      scalbn
#define scalblnf     scalbln

#define fabsf        fabs
#define hypotf       hypot

#define powf         pow
#define sqrtf        sqrt
#define cbrtf        cbrt

#define erff         erf
#define erfcf        erfc
#define lgammaf      lgamma
#define tgammaf      tgamma

#define ceilf        ceil
#define floorf       floor
#define nearbyintf   nearbyint
#define rintf        rint
#define lrintf       lrint
#define llrintf      llrint
#define roundf       round
#define lroundf      lround
#define llroundf     llround
#define truncf       trunc

#define modff        modf
#define fmodf        fmod
#define remainderf   remainder
#define remquof      remquo

#define copysignf    copysign
#define nanf         nan

#define nextafterf   nextafter
#define nexttowardf  nexttoward

#define fdimf        fdim

#define fmaxf        fmax
#define fminf        fmin

#define fmaf         fma

#endif