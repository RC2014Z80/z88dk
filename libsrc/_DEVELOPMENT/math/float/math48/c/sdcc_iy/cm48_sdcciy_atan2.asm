
; float atan2(float y, float x)

SECTION code_fp_math48

PUBLIC cm48_sdcciy_atan2

EXTERN cm48_sdcciyp_dread2, l0__cm48_sdcciy_atan2_callee

cm48_sdcciy_atan2:

   call cm48_sdcciyp_dread2
   
   ; AC = x
   ; AC'= y
   
   jp l0_cm48_sdcciy_atan2_callee