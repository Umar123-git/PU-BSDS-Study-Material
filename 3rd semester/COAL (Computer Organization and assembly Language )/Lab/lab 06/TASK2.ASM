.model small
.stack 100h
.data

input db 13,10, "Enter a character : $"
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




display:
	
	mov dx, offset newline
	mov ah, 09h
	int 21h

	mov dl,bl
	mov ah,02h
    	int 21h


	mov dx, offset newline
	mov ah, 09h
	int 21h

mov cx,2
first:
	ror bl,1
	ror bl,1
	ror bl,1
	ror bl,1

	mov dl,bl
	and dl,0Fh
	cmp dl,9

	jbe digit
	add dl,7       ; 10–15 → 'A'–'F'
	digit:
	add dl,30h     ; 0–15 → '0'–'9','A'–'F'
	mov ah,02h
	int 21h
	
	dec cx
	jnz first

	jmp again
	
exit:	mov ah,4ch
	int 21h
	main endp
	end main
