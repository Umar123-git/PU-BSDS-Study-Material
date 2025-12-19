.model small
.stack 100h
.data

cap db "CAPITAL$"
sm db "SMALL$"
input db "Enter a character : $" 

.code
main proc
mov ax,@data
mov ds,ax


mov dx, offset input
mov ah,09h
int 21h

mov ah,01h
int 21h

cmp al,97
jae small
jmp capital

capital:
	mov ah,09h
	mov dx, offset cap
	int 21h
	jmp exit

small:
	mov ah,09h
	mov dx,offset sm
	int 21h
	jmp exit
	 

	
exit:
	mov ah,4ch
	int 21h
	main endp
	end main
