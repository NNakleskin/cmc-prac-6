

section .data
    op db `%lf`, 0

section .bss
    x resb 8

section .text

f1:
    push ebp
    mov ebp, esp
    push ecx
    push ebx
    finit
    fld1
    add eax, 3

f2:


f3:
    push ebp
    mov ebp, esp
    push ecx
    push ebx
    finit
    fld1
    fld qword[esp + 8]
    fdivp
    fstp qword[eax]
    add eax, 3
    pop ebx
    pop ecx
    mov esp, ebp
    pop ebp
    ret


    
    
extern scanf
extern printf
global CMAIN
CMAIN:
    sub esp, 4
    push x
    push op

    call scanf

    add esp, 12


    push x
    call f3
    add esp, 8


    sub esp, 4
    push dword[x]
    push op
    call printf
    add esp, 12

    xor eax, eax
    ret