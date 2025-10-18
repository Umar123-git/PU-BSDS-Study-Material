.model small
.stack 100h
.data
msg1 db "Enter a binary number up to 8 digits: $"
msg2 db 13,10,"The binary sum is: $"
msg3 db 13,10,"The hex sum is: $"
error db 13,10,"Illegal binary digit, try again.",13,10,'$'
newline db 13,10,'$'
input1 db 9, ?, 9 dup(?)   ; max 8 digits
input2 db 9, ?, 9 dup(?)
table db "0123456789ABCDEF"

.code
main proc
    mov ax, @data
    mov ds, ax

get_first:
    mov dx, offset msg1
    mov ah, 09h
    int 21h

    mov dx, offset input1
    mov ah, 0Ah
    int 21h

    mov si, offset input1 + 2
    mov cl, input1[1]
    cmp cl, 0
    je get_first

validate1:
    mov al, [si]
    cmp al, '0'
    je ok1
    cmp al, '1'
    je ok1
    jmp error1
ok1:
    inc si
    dec cl
    jnz validate1

get_second:
    mov dx, offset msg1
    mov ah, 09h
    int 21h

    mov dx, offset input2
    mov ah, 0Ah
    int 21h

    mov si, offset input2 + 2
    mov cl, input2[1]
    cmp cl, 0
    je get_second

validate2:
    mov al, [si]
    cmp al, '0'
    je ok2
    cmp al, '1'
    je ok2
    jmp error2
ok2:
    inc si
    dec cl
    jnz validate2

    ; Convert input1 to integer
    xor ax, ax
    mov si, offset input1 + 2
    mov cl, input1[1]
conv1:
    shl ax, 1
    mov bl, [si]
    cmp bl, '1'
    jne skip1
    inc ax
skip1:
    inc si
    dec cl
    jnz conv1
    mov bx, ax    ; BX = first number

    ; Convert input2 to integer
    xor ax, ax
    mov si, offset input2 + 2
    mov cl, input2[1]
conv2:
    shl ax, 1
    mov bl, [si]
    cmp bl, '1'
    jne skip2
    inc ax
skip2:
    inc si
    dec cl
    jnz conv2

    add ax, bx    ; AX = sum

    ; Print binary sum
    mov dx, offset msg2
    mov ah, 09h
    int 21h

    mov cx, 16
    mov bx, ax
    mov si, 0
    mov di, 0      ; flag to skip leading zeros

print_bin:
    mov dx, bx
    shl dx, 1
    jc one
    mov dl, '0'
    jmp show
one:
    mov dl, '1'
show:
    cmp dl, '1'
    je set_flag
    cmp di, 1
    jne skip_print
set_flag:
    mov di, 1
skip_print:
    cmp di, 1
    jne skip_output
    mov ah, 02h
    int 21h
skip_output:
    inc si
    loop print_bin

    ; Print hex sum
    mov dx, offset msg3
    mov ah, 09h
    int 21h

    mov bx, ax
    mov cx, 4
print_hex:
    mov ax, cx
    dec ax
    shl ax, 2         ; shift amount = (cx-1)*4
    mov cl, al
    mov ax, bx
    shr ax, cl
    and al, 0Fh
    mov si, offset table
    add si, ax
    mov dl, [si]
    mov ah, 02h
    int 21h
    loop print_hex

    ; Exit
    mov ah, 4Ch
    int 21h

error1:
    mov dx, offset error
    mov ah, 09h
    int 21h
    jmp get_first

error2:
    mov dx, offset error
    mov ah, 09h
    int 21h
    jmp get_second

main endp
end main