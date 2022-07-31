; Aidan Hopper
; 42236214
; I pledge that this submission is solely my work, and that I have neither given, nor received help from anyone.

    section .data
a   dq -326
b   dq 7
rem dq 0
quo dq 0
    section .text
    global main
main:
    mov rax, [a]    ; storing var a in rax
    neg rax         ; swapping the sign of rax to positive
    mov rdx, 0      ; 0ing out rdx
    div qword [b]   ; dividing by var b
    neg rax         ; swapping sign of rax to negative
    neg rdx         ; swapping sign of rdx to negative
    mov [quo], rax  ; saving quotient
    mov [rem], rdx  ; saving remainder
    ret

