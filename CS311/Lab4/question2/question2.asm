; Aidan Hopper
; 42236214
; I pledge that this submission is solely my work, and that I have neither given, nor received help from anyone.

    section .data
x   dq 100, 100
y   dq 100, 50
yd  dq 0
xd  dq 0
    section .text
    global main
main:
    ; getting x distance
    lea rcx, [y]            ; gets location of x array
    mov rax, [rcx]          ; moves 1 byte of x array into rax
    add rcx, 8              ; increments memory location by 1 
    mov rbx, [rcx]          ; moves next byte of array x into rbx
    sub rax, rbx            ; subtracts rbx from rax
    mov [yd], rax           ; saves x distance
    ; getting y distance
    lea rcx, [x]            ; gets location of x array
    mov rax, [rcx]          ; moves 1 byte of x array into rax
    add rcx, 8              ; increments memory location by 1 
    mov rbx, [rcx]          ; moves next byte of array x into rbx
    sub rax, rbx            ; subtracts rbx from rax
    mov [xd], rax           ; saves x distance
    ; checking if xd == 0
    mov rbx, 1              ; using rbx to transfer if rax is 0
    cmovz rax, rbx          ; checking if rax is 0
    mov rbx, 0              ; using rbx to transfer if rax is 1
    cmovnz rax, rbx         ; checking if rax is not 0
    ret
