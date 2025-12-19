.model small
.stack 100h
.data

table db 65 dup(0)
      db 'F','V','X','C','H','S','A','I','Y','Q','W','G','O','T','B','N','Z','K','M','J','P','L','U','R','D','E'
      db 165 dup(0)

table1 db 65 dup(0)
       db 'G','O','D','Y','Z','A','L','E','H','T','R','V','S','P','M','U','J','X','F','N','W','B','K','C','I','Q'
       db 165 dup(0)

prompt  db "Enter string: $"
msg1    db 13,10,"Encoded: $"
msg2    db 13,10,"Decoded: $"

input   db 100 dup(0)
output  db 101 dup(0)
output1 db 101 dup(0)

.code
start:
    mov ax,@data
    mov ds,ax

    mov ah,9
    mov dx,offset prompt
    int 21h

    mov si,offset input

read_loop:
    mov ah,1
    int 21h
    cmp al,13
    je encode_start
    mov [si],al
    inc si
    jmp read_loop

encode_start:
    mov al,0
    mov [si],al
    mov si,offset input
    mov di,offset output
    mov bx,offset table

encode_loop:
    mov al,[si]
    cmp al,0
    je show_encoded
    
    xlat
    mov [di],al
    inc si
    inc di
    jmp encode_loop

show_encoded:
    mov al,'$'
    mov [di],al
    mov ah,9
    mov dx,offset msg1
    int 21h
    mov ah,9
    mov dx,offset output
    int 21h

    mov si,offset output
    mov di,offset output1
    mov bx,offset table1

decode_loop:
    mov al,[si]
    cmp al,'$'
    je show_decoded

    xlat
    mov [di],al
    inc si
    inc di
    jmp decode_loop

show_decoded:
    mov al,'$'
    mov [di],al
    mov ah,9
    mov dx,offset msg2
    int 21h
    mov ah,9
    mov dx,offset output1
    int 21h

    mov ah,4Ch
    int 21h
end start