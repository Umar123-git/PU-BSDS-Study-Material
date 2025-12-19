.model small
.stack 100h
.data

table db 65 dup(0)
      db 'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C'

prompt db "Enter string: $"
msg    db 13,10,"Shifted: $"

input  db 100 dup(0)
output db 100 dup('$')

.code
start:
    mov ax, @data
    mov ds, ax


    mov ah, 9
    mov dx, offset prompt
    int 21h


    mov si, offset input
read_loop:
    mov ah, 1
    int 21h        ; AL
    cmp al, 13     
    je process
    mov [si], al
    inc si
    jmp read_loop


process:
    mov si, offset input
    mov di, offset output

next_char:
    mov al, [si]
    cmp al, 0
    je show

    mov bx, offset table
    xlat            

    mov [di], al
    inc si
    inc di
    jmp next_char

show:
    mov ah, 9
    mov dx, offset msg
    int 21h

    mov ah, 9
    mov dx, offset output
    int 21h


    mov ah, 4Ch
    int 21h
end start
