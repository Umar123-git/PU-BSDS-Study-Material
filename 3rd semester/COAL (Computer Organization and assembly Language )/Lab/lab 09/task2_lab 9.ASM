.model small
.stack 100h

.data
msg     db 0Ah,0Dh,'Enter ASCII value (0-127): $'
output  db 0Ah,0Dh,'The binary is: $'

; XLAT uses DS:BX as table base
encryption_table db 125,126,127,0,1,2,3,4,5,6,7,8,9,10,11,12
                 db 13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28
                 db 29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44
                 db 45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60
                 db 61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76
                 db 77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92
                 db 93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108
                 db 109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124

.code
main proc
    mov ax, @data
    mov ds, ax

; -------------------------
; PRINT PROMPT
; -------------------------
    mov ah, 09h
    lea dx, msg
    int 21h

; -------------------------
; READ ONE ASCII DIGIT
; -------------------------
    mov ah, 01h
    int 21h
    sub al, '0'        ; convert ASCII → number
    mov bl, al         ; BL = index for XLAT

; -------------------------
; ENCRYPT USING XLAT
; -------------------------
    mov bx, offset encryption_table   ; BX = table base
    xlat                              ; AL = encryption_table[BL]

; -------------------------
; PRINT OUTPUT MESSAGE
; -------------------------
    mov ah, 09h
    lea dx, output
    int 21h

; -------------------------
; PRINT 8-BIT BINARY OF AL
; -------------------------
    mov cx, 8          ; print 8 bits
print_loop:
    shl al, 1
    jc print1
    mov dl, '0'
    jmp show

print1:
    mov dl, '1'

show:
    mov ah, 02h
    int 21h
    loop print_loop

; -------------------------
; EXIT
; -------------------------
    mov ah, 4Ch
    int 21h

main endp
end main
