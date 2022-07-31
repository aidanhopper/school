; Aidan Hopper
; 42236214
; I pledge that this submission is solely my work, and that I have neither given, nor received help from anyone.
        
    segment .data
scanf_format    db  "%ld",0
printf_format   db  "The closest to the fib(%ld) is = %ld",0x0a,0
x   dq 0
    segment .text
    global main
    global fib
    extern scanf
    extern printf
    
fib:
    push rbp
    mov rbp, rsp
    frame 1, 2, 1
    sub rsp, frame_size     ; setting up stack frame

f1  equ local1
f2  equ local2              ; creating local vars
    mov rax, 1
    mov [rsp+f1], rax       ; populating local vars
    mov [rsp+f2], rax
    
    ;mov rax, [rsp+f1]       ; moving vars into registers
   ; mov rbx, [rsp+f2]
    
    cmp rcx, 2
    jle end                ; skips if n <= 2
    
    mov r8, rcx             ; using r8 and r9 to calculate diff 
    mov r9, rcx

    jmp while               ; jumps to while loop
    
end:                        ; end of function calls printf on closest fib num
    mov rdx, rcx
    mov r8, [rsp+f2]
    lea rcx, [printf_format]
    call printf
    leave
    ret

iszero:                     ; returns correct num if n is fib number
    mov [rsp+f2], rcx
    jmp end

negate:                     ; takes absolute value of r8
    neg r8
    jmp next
    

while:
    mov rax, [rsp+f1]       ; moving vars into registers
    mov rbx, [rsp+f2]
    
    add rbx, rax            ; new fib num in rbx
    
    mov [rsp+f2], rax       ; saving new nums to stack
    mov [rsp+f1], rbx
    
    sub r8, rbx             ; checks to see if difference is smaller than last loop
    cmp r8, 0
    jl negate
    jmp next
next:                       ; used to jump to when negate is used
    cmp r8, 0
    jz iszero
    cmp r8, r9
    jge end
    mov r9, r8
    mov r8, rcx
    
    jmp while
    
main:                       ; starts by getting integer input from scanf
    push rbp
    mov rbp, rsp
    frame 0, 0, 1
    sub rsp, frame_size     ; setting up the stack frame
    lea rcx, [scanf_format] ; passing format as argument
    lea rdx, [x]            ; passing global var as return addr
    call scanf              ; calling scanf function
    mov rcx, [x]
    call fib
    mov rax, [x]
    call printf
    ret
