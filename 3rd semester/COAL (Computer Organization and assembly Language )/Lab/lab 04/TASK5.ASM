.model small
.stack 100h
.data
array db 1, 2, 3, 4, 5, 6, 7, 8
.code
main proc
mov ax,@data
mov ds,ax
mov si, offset array
mov cx,8

mov ah,01h
int 21h
mov bl,al

mov ah, 02h
mov dl, 0Dh   
int 21h
mov dl,0ah
int 21h

again:	add [si],bl
        inc si
        dec cx
        jnz again

mov si, offset array
mov cx,8

mov ah,02h

test1:	mov dl,[si]
	int 21h
	inc si
	dec cx
	jnz test1


mov ah,4ch
int 21h
main endp
end main
