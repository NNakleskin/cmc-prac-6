%include "io.inc"

section .rodata
    op db `%lf`, 0

CEXTERN scanf
CEXTERN printf

section .text
global CMAIN
CMAIN:
    mov ecx, esp
    and esp, 0xfffffff0
    push ecx
    sub esp, 28
    lea eax, [esp+20]

    mov [esp + 4], eax
    mov dword[esp], op
    call scanf
    cmp eax, 1
    jne .epilog

    finit 
    fld1
    fld qword[esp + 20]
    fdivp
    fstp qword[esp + 20]

    mov eax, [esp + 20]
    mov [esp + 4], eax
    mov eax, [esp + 24]
    mov [esp + 8], eax
    mov dword[esp], op
    call printf

    .epilog:
    add esp, 28
    pop ecx
    mov esp, ecx

    xor eax, eax
    ret
