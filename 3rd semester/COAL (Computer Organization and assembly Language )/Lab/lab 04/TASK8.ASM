.model small
.stack 100h
.data

errormsg db "Error! Sum is greater than 9.$"
summsg db "Sum is $"
input db "Enter two digits : $" 

.code
main proc
mov ax,@data
mov ds,ax


mov dx, offset input
mov ah,09h
int 21h

mov ah,01h
int 21h
sub al,30h
mov bl,al

mov ah,01h
int 21h
sub al,30h

add bl,al

cmp bl,10
jb sum
jmp error

error:
	mov ah,09h
	mov dx, offset errormsg
	int 21h
	jmp exit

sum:	mov dx,offset summsg
	mov ah,09h
	int 21h

	add bl,30h
 	mov dl,bl
	mov ah,02h
	int 21h
	jmp exit
	 

	
exit:
	mov ah,4ch
	int 21h
	main endp
	end main
