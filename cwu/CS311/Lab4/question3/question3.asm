; Aidan Hopper
; 42236214
; I pledge that this submission is solely my work, and that I have neither given, nor received help from anyone.

    section .data
a   dq 36
b   dq 43
c   dq 12
d   dq 98
tot dq 4
avg dq 0
rem dq 0
    section .text
    global main
main:
    mov rax, [a]        ; adding grades together in rax
    add rax, [b]
    add rax, [c]
    add rax, [d]
    mov rdx, 0          ; 0ing out rdx 
    idiv qword [tot]    ; dividing rax by tot var 
    mov [avg], rax      ; saving average
    mov [rem], rdx      ; saving remainder
    ret
