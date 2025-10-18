.model small
.stack 100h
.data

message db "Enter a binary number up to 16 digits: $"
error db 13,10,"Illegal binary digit, try again.",13,10,'$'
ans db 13,10,"In Hex it is: $"
input db 17, ?, 17 dup(?)       ; buffer for input string
newline db 13,10,'$'
table db "0123456789ABCDEF"    ; hex digit lookup table

.code
main proc
    mov ax, @data
    mov ds, ax

start:
    ; print message
    mov dx, offset message
    mov ah, 09h
    int 21h

get_input:
    ; get string from user
    mov dx, offset input
    mov ah, 0Ah
    int 21h

    mov si, offset input + 2
    mov cl, input[1]        ; number of chars entered
    cmp cl, 0
    je start                ; if empty input, ask again

    ; check for invalid characters
check:
    mov al, [si]
    cmp al, '0'
    je valid
    cmp al, '1'
    je valid
    jmp error_input

valid:
    inc si
    dec cl
    jnz check

    ; print newline
    mov dx, offset newline
    mov ah, 09h
    int 21h

    ; print answer message
    mov dx, offset ans
    mov ah, 09h
    int 21h

    ; convert binary to decimal in AX
    xor ax, ax
    mov si, offset input + 2
    mov cl, input[1]

convert:
    shl ax, 1
    mov bl, [si]
    cmp bl, '1'
    jne skip
    inc ax
skip:
    inc si
    dec cl
    jnz convert

    ; print hex digits manually
    mov bx, ax            ; BX holds the binary value
    mov cx, 4             ; We want to print 4 hex digits

print_hex:
    mov ax, cx
    dec ax
    shl ax, 2             ; AX = (cx - 1) * 4
    mov cl, al            ; CL = shift amount

    mov ax, bx
    shr ax, cl
    and al, 0Fh           ; isolate nibble

    mov si, offset table
    add si, ax
    mov dl, [si]

    mov ah, 02h
    int 21h

    loop print_hex

    jmp exit

error_input:
    mov dx, offset error
    mov ah, 09h
    int 21h
    jmp start

exit:
    mov ah, 4Ch
    int 21h

main endp
end main