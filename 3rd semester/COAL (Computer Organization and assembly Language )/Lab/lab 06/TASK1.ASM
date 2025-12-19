.model small
.stack 100h
.data

input db "Enter a character : $"
newline db 13,10,'$' 

.code
main proc
mov ax,@data
mov ds,ax

mov dx, offset input
mov ah,09h
int 21h 

mov ah,01h
int 21h

mov dx, offset newline
mov ah, 09h
int 21h

mov bl,al

mov cl,0
mov ch,8
again:  shl bl,1
	jc one
	mov dl,'0'
	mov ah,02h
	int 21h
	dec ch
	jnz again
	jmp exit
        
	

one:
	mov dl,'1'
	mov ah,02h
	int 21h
	inc cl
	dec ch
	jnz again
	jmp exit

	
exit:
mov dx, offset newline
mov ah, 09h
int 21h

mov dl,cl
add dl,30h
mov ah,02h
int 21h

mov ah,4ch
int 21h
main endp
end main
