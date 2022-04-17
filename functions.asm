section .rodata
    a dw 2
    b dw 4

section .text
global f1
global f2
global f3


f1:
    fld qword[esp + 4]
    fchs
    fldl2e
    fmulp
    f2xm1
    fild word[b]
    ret

f2:
    fld qword[esp + 4]
    fild word[a]
    fmulp
    fild word[a]
    fsubp
    ret

f3:
    fld1
    fld qword[esp + 4] 
    fdivp
    ret