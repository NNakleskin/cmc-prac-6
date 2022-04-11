%include "io.inc"

section .text
CEXTERN exp

f1:
    push ebp
    mov ebp, esp
    push ecx
    push ebx
    
    mov ebx, dword[esp + 8]
    mov eax, 1
    cdq
    div eax
    ;непонятно как работать с double при делении
    
    add eax, 3
    
    

global CMAIN
CMAIN:
    
    xor eax, eax
    ret