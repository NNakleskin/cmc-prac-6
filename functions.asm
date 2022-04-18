section .rodata
    a dw 2
    b dw 3
    

section .text
global f1
global f2
global f3
extern exp


f1:
    fld qword[esp + 4]
    fchs
    sub esp, 8
    fstp qword[esp]
    call exp
    add esp, 8
    fild word[b]
    faddp
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