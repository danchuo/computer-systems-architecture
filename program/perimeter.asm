;------------------------------------------------------------------------------
; perimeter.asm - единица компиляции, вбирающая функции вычисления периметра
;------------------------------------------------------------------------------

;----------------------------------------------
; Вычисление периметра прямоугольника
;double PerimeterRectangle(void *r) {
;    return 2.0 * (*((int*)r) + *((int*)(r+intSize)));
;}
global GeneralFunction
GeneralFunction:
section .text
push rbp
mov rbp, rsp

	; В rdi адрес 
    mov edx, 0
    mov eax, [rdi+4]
    mov ecx, [rdi]
    div ecx
    cvtsi2sd    xmm0, eax

leave
ret
