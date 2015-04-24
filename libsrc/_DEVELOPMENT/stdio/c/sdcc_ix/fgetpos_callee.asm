
; int fgetpos_callee(FILE *stream, fpos_t *pos)

INCLUDE "clib_cfg.asm"

SECTION code_stdio

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
IF __CLIB_OPT_MULTITHREAD & $02
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUBLIC _fgetpos_callee, l0_fgetpos_callee

_fgetpos_callee:

   pop af
   pop bc
   pop hl
   push af

l0_fgetpos_callee:

   push bc
   ex (sp),ix
   
   call asm_fgetpos
   
   pop ix
   ret
   
   INCLUDE "stdio/z80/asm_fgetpos.asm"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ELSE
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUBLIC _fgetpos_callee

EXTERN _fgetpos_unlocked_callee

defc _fgetpos_callee = _fgetpos_unlocked_callee
   
INCLUDE "stdio/z80/asm_fgetpos.asm"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ENDIF
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;