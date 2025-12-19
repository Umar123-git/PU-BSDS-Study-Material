.model small
.stack 100h
.data
array db 1, 2, 3, 4, 5, 6, 7, 8
array2 db 8 dup(00)
.code
main proc
mov ax,@data
mov ds,ax
mov si, offset array
mov di, offset array2
mov cx,8
again:  mov al,[si]
	mov [di],al
        mov dl,[di]
	add dl,48
	mov ah,02
	int 21h
        inc si
        inc di
        dec cx
        jnz again
mov ah,4ch
int 21h
main endp
end main
