.model small
.stack 100h
.data
array db 1, 2, 3, 4, 5, 6, 7, 8
array2 db 41h, 42h, 43h, 44h, 45h, 46h, 47h, 48h
.code
main proc
mov ax,@data
mov ds,ax
mov si, offset array
mov di, offset array2
mov cx,8
again:  mov al,[si]
	mov bl,[di]
	mov [si],bl
	mov [di],al
        inc si
        inc di
        dec cx
        jnz again
mov si, offset array
mov di, offset array2
mov cx,8

mov ah,02h

test1:	mov dl,[si]
	int 21h
	inc si
	dec cx
	jnz test1

mov cx,8

test2:	mov dl,[di]
	add dl,48
	mov ah,02
	int 21h
	inc di
	dec cx
	jnz test2
mov ah,4ch
int 21h
main endp
end main
