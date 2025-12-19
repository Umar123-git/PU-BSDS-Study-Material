.model small
.stack 100h
.data

myname db "Muhammad Umar Shafiq$"
rollNo db "BSDSF24A050$" 
newline db 13,10,'$' 

.code
main proc
mov ax,@data
mov ds,ax



mov cx,2
mainprocedure:
	cmp cx,2
	mov dx, offset myname
	je procedure
	
	mov dx, offset rollNo
	jmp procedure

procedure:
	mov ah,09h
	int 21h
	dec cx

	mov dx, offset newline
	mov ah, 09h
	int 21h

	jnz mainprocedure
	jmp exit


	
	
exit:	mov ah,4ch
	int 21h
	main endp
	end main
