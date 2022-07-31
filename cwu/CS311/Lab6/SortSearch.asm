; Aidan Hopper
; 42236214
; I pledge that this submission is solely my work, and that I have neither given, nor received help from anyone.
    
    segment .data
a       dd 12, 14, 7, 45, 21, 15, 57, 36, 3, 79
swapped db 1
loc     db 0
    segment .text
    global main
main:
    jmp while           ; jumps to while loop

while:
    mov rbx, [swapped]  ; moves swapped bool into rbx
    cmp rbx, 1          ; compares rbx to 1
    jnz bsa             ; if cmp returned 0 then end while loop jumping to bsa
    mov rcx, 0          ; set rcx to 0
    mov ax, 0           ; moves 0 into ax to set swapped to 0
    mov [swapped], ax
    jmp for             ; jumps to for loop

end_while:
    xor r8, r8
    xor r9, r9
    xor r10, r10
    xor rax, rax
    xor rbx, rbx
    xor rcx, rcx
    xor rdx, rdx
    ret

for:
    cmp rcx, 9          ; compares rcx to size of array-1
    jnl while           ; if not less than then jumps to while
    
    mov r10, 0          ; sets r10 to 0
    add r10, rcx        ; adds loop counter to rcx
    shl r10, 2          ; multiplies r10 by 4
    
    lea rdx, [a]        ; gets the memory address of a
    add rdx, r10        ; adds index*4 to memory address
    mov eax, [rdx]      ; moves value at location rdx into eax
    add rdx, 4          ; adds 4 memory address
    mov ebx, [rdx]      ; effecively gets a[i] and a[i+1]
    
    cmp eax, ebx        ; compares eax to ebx and if eax is not less than
    jnl if              ; triggers jump
    
    inc rcx             ; increments loop counter
    jmp for             ; jumps back to top of for loop
    
if:
    lea rdx, [a]        ; gets memory address of a
    add rdx, r10        ; loop counter * 4 to memory address
    mov [rdx], ebx      ; moves ebx into mem location
    add rdx, 4          ; adds 4 to mem address
    mov [rdx], eax      ; moves eax into mem location effectivley performing an index swap
    mov ax, 1           ; moves 1 into ax
    mov [swapped], ax   ; sets swapped equal to 1 signifying true
    inc rcx             ; increments rcx
    jmp for             ; jumps to top of for loop
    
bsa:
    mov rax, 0          ; sets lower index
    mov rbx, 9          ; sets upper index
    jmp while2          ; jumps to while loop
    
while2:
    cmp rax, rbx        ; checks if rax is less than rbx
    jge end_while
    
    mov rcx, rax
    add rcx, rbx
    shr rcx, 1          ; sets rcx to middle
    
    mov r8, rcx
    shl r8, 2           ; gets length of index and puts it into r8
    
    lea r9, [a]
    add r9, r8          ; gets memory address of middle value
    
    mov edx, [r9]       ; gets value a mem address stored in r9 
    
    cmp edx, 21         ; compares a[i] with 21
    jz found21          ; if cmp returns 0 then 21 was found
    jnl else_if         ; if a[i] is less than 21 then jumps to else_if
    mov rax, rcx        ; else moves middle into lower value then adds 1
    inc rax
    
    jmp while2          ; jumps to top of while loop

found21:
    mov [loc], cx
    jmp end_while 
    
else_if:
    mov rbx, rcx        ; moves middle into upper value then subtracts 1
    dec rbx
    jmp while2          ; jumps to top of while2

