; 32bit mode !!!!
section .data
    msg db "Hello, World!", 0
    msg_len equ $ - msg

section .bss
    data: resb 100

section .text
    global _start
_start:
    ; fork child process
    mov eax, 2
    int 0x80
    mov ebx, eax
    cmp eax, 0
    je _child

    ; parent process
    _parent:
        ; wait for child process to finish
        mov eax, 7 ; sys_poll
        mov ebx, ebx
        int 0x80

    _child:
        mov eax, 1
        mov ebx, 1
        mov ecx, data
        mov edx, 100
        int 0x80
        mov eax, 1
        mov ebx, 0
        int 0x80