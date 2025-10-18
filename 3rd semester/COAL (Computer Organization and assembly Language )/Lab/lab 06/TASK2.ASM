.model small
.stack 100h
.data

input db "Enter a character : $"
newline db 13,10,'$' 

.code
main proc
mov ax,@data
mov ds,ax


mov dx, offset newline
mov ah, 09h
int 21h


;mov cx,8
again: 	mov dx, offset input
	mov ah,09h
	int 21h

	mov ah,01h
	int 21h 
	
	mov bl,al
	cmp bl,13
	je exit
	jmp display

mov ah,01h
int 21h 


display:
	
	mov dx, offset newline
	mov ah, 09h
	int 21h

	;sub dl,61h
	sub dl,24
	mov ah,02h
        int 21h

	mov dx, offset newline
	mov ah, 09h
	int 21h

	jmp again
	
exit:	mov ah,4ch
	int 21h
	main endp
	end main
