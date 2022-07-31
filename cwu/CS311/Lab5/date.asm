; Aidan Hopper
; 42236214
; I pledge that this submission is solely my work, and that I have neither given, nor received help from anyone.

        segment .data
    t       dw  0x65A9
    day     dw  0
    month   db  0
    year    dw  1980
    
        segment .text
        global main
main:
    xor EDX, EDX
    mov DX, [t]         ; moving t into dx
    mov BX, [year]      ; moving year into bx for later use
    and DX, 0x1f        ; clearing DX with mask of 11111
    mov [day], DX       ; saving dx into day
    mov DX, [t]         ; moving t into dx
    shr DX, 5           ; shifting dx 5 bits right
    and DX, 0xF         ; clearing dx with mask of 1111
    mov [month], DX     ; saving dx into month
    mov DX, [t]         ; moving t into dx
    shr DX, 9           ; shifting dx 9 bits right
    add BX, DX          ; adding dx to year
    mov [year], BX      ; saving newly calculated year
    xor DX, DX
    xor BX, BX
    ret
    
