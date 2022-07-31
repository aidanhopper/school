; Aidan Hopper
; 42236214
; I pledge that this submission is solely my work, and that I have neither given, nor received help from anyone.
    
    segment .data
a   dw -278, 124, -172
b   db 38, -120, -92
sum dq 0
    segment .text
    global main
main:    
    ; left half i = 0
    lea rbx, [b]                 ; rax stores memory address of array
    movsx rax, byte [rbx]        ; rbx stores value at index i in array a
    sub rax, 10                  ; adds 10 to rbx register
    lea rbx, [a]                 ; gets memory address of array b
    movsx rcx, word [rbx]        ; moves value at index i in array b
    add rax, rcx                 ; adding array a index i to array b at index i
    mov [sum], rax               ; saving rax to the sum
    ; sum = -250
    
    ; right half i = 0
    lea rbx, [b]                 ; moving memory address of array a into rbx
    movsx rax, byte [rbx]        ; moving first byte in array into rax
    add rax, 32                  ; adding 32 rax
    lea rbx, [a]                 ; moving memory address of array a into rbx
    movsx rcx, word [rbx]        ; moving first word in array into rcx
    sub rax, rcx                 ; subtracting rcx from rax
    mov rbx, [sum]               ; moving the sum into rbx
    add rbx, rax                 ; adding rax to rbx
    mov [sum], rbx               ; saving the sum
    ; sum  = 98
    
    ; left half i = 1
    lea rbx, [b]                 ; moving memory address of array a into rbx
    add rbx, 1                   ; incrementing memotry address by 1 byte
    movsx rax, byte [rbx]        ; moving second byte in array into rax
    sub rax, 10                  ; adding 32 rax
    lea rbx, [a]                 ; moving memory address of array a into rbx
    add rbx, 2                   ; incrementing memory address by 1 word
    movsx rcx, word [rbx]        ; moving second word in array into rcx
    add rax, rcx                 ; subtracting rcx from rax
    mov rbx, [sum]               ; moving the sum into rbx
    add rbx, rax                 ; adding rax to rbx
    mov [sum], rbx               ; saving the sum
    ; sum  = 92
    
    ; right half i = 1
    lea rbx, [b]                 ; moving memory address of array a into rbx
    add rbx, 1                   ; incrementing memotry address by 1 byte
    movsx rax, byte [rbx]        ; moving second byte in array into rax
    add rax, 32                  ; adding 32 rax
    lea rbx, [a]                 ; moving memory address of array a into rbx
    add rbx, 2                   ; incrementing memory address by 1 word
    movsx rcx, word [rbx]        ; moving second word in array into rcx
    sub rax, rcx                 ; subtracting rcx from rax
    mov rbx, [sum]               ; moving the sum into rbx
    add rbx, rax                 ; adding rax to rbx
    mov [sum], rbx               ; saving the sum
    ; sum  = -120
    
    ; left half i = 2
    lea rbx, [b]                 ; moving memory address of array a into rbx
    add rbx, 2                   ; incrementing memotry address by 1 byte
    movsx rax, byte [rbx]        ; moving third byte in array into rax
    sub rax, 10                  ; adding 32 rax
    lea rbx, [a]                 ; moving memory address of array a into rbx
    add rbx, 4                   ; incrementing memory address by 1 word
    movsx rcx, word [rbx]        ; moving third word in array into rcx
    add rax, rcx                 ; subtracting rcx from rax
    mov rbx, [sum]               ; moving the sum into rbx
    add rbx, rax                 ; adding rax to rbx
    mov [sum], rbx               ; saving the sum
    ; sum  = -394
    
    ; right half i = 2
    lea rbx, [b]                 ; moving memory address of array a into rbx
    add rbx, 2                   ; incrementing memotry address by 2 bytes
    movsx rax, byte [rbx]        ; moving third byte in array into rax
    add rax, 32                  ; adding 32 rax
    lea rbx, [a]                 ; moving memory address of array a into rbx
    add rbx, 4                   ; incrementing memory address by 2 words
    movsx rcx, word [rbx]        ; moving third word in array into rcx
    sub rax, rcx                 ; subtracting rcx from rax
    mov rbx, [sum]               ; moving the sum into rbx
    add rbx, rax                 ; adding rax to rbx
    mov [sum], rbx               ; saving the sum
    ; sum  = -282
    
    xor rax, rax                 ; clearing rax
    xor rbx, rbx                 ; clearing rbx
    xor rcx, rcx                 ; clearing rcx
    ret                          ; ending program
    
