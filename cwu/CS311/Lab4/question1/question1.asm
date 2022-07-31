; Aidan Hopper
; 42236214
; I pledge that this submission is solely my work, and that I have neither given, nor received help from anyone.
    
    segment .data
a   db 15               ; creating var a size of byte
b   db 5                ; creating var b size of byte
pro dq 0                ; creating var pro size of 8 bytes
    segment .text
    global main
main:
    movsx rax, byte [a] ; moves single byte of var a into rax
    movsx rbx, byte [b] ; moves single byte of var b into rbx
    sub rax, rbx        ; subtracts rbx from rax to get difference
    imul rax, rax       ; multiplies rax by itself effectively computing the square
    mov [pro], rax      ; saves rax into the var pro
    xor rax, rax        ; clears register
    xor rbx, rbx        ; clears register
    ret                 ; returns

