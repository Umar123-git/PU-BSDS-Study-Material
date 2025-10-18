.model small
.stack 100h
.data

arr1 db 1, 2, 3, 4, 5, 6, 7, 8
arr2 db 8, 7, 6, 5, 4, 3, 2, 1
arr3 db 8 dup(00)
newline db 13,10,'$' 

.code
main proc
mov ax,@data
mov ds,ax


mov bx, offset arr1
mov si, offset arr2
mov di, offset arr3

mov cx,8

add_procedure:
	
	mov al,[bx]
	mov [di],al
	mov al,[si]
	add [di],al

	mov dl,[di]
	add dl,30h
	mov ah,02h
	int 21h

	mov dl,','
	mov ah, 02h
	int 21h

	;dec cx
	inc si
	inc di
	inc bx

	loop add_procedure


	mov ah,4ch
	int 21h
	main endp
	end main
