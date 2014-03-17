
; ===============================================================
; Mar 2014
; ===============================================================
; 
; int ba_stack_top(ba_stack_t *s)
;
; Return char at top of stack without removing it.
; If the stack is empty, return -1.
;
; ===============================================================

XLIB asm_ba_stack_top

LIB asm_b_array_back

defc asm_ba_stack_top = asm_b_array_back

   ; enter : hl = stack *
   ;
   ; exit  : success
   ;
   ;            de = & last char in stack
   ;            hl = last char in stack
   ;            carry reset
   ;
   ;         fail if stack is empty
   ;
   ;            hl = -1
   ;            carry set, errno = EINVAL
   ;
   ; uses  : af, bc, de, hl
