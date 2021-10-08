; Aidan Hopper
; 42236214
; I pledge that this submission is solely my work, and that I have neither given, nor received help from anyone.
    
            segment .data       ; data segment for declaring constants
a   db 33               ; allocating 1 byte for integer 33
b   dw 35               ; allocating 2 bytes for integer 35
c   dd 123              ; allocating 4 bytes for integer 123
d   dd 29.659           ; allocating 4 bytes for floating point number
e   dw 32452            ; allocating 2 bytes for integer because 2^7 < 32452 < 2^15
    segment .bss        ; bss segment for allocating memory
g   resw 10             ; reserving 10 words aka 20 bytes
h   resb 50             ; reserving 50 bytes
i   resd 15             ; reserving 15 double words aka 60 bytes
    segment .text       ; text segment
    global main         ; telling linker about main
main:
