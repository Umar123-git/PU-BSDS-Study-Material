.model small
.stack 100h
.data

message db "Enter a hex Number of four digits or less (0 to FFFF): $"
error db "Illegal hex digit, try again: $"
ans db "In binary it is: $"
input db 5, ?, 5 dup(?)
newline db 13,10,'$' 

.code
main proc
mov ax,@data
mov ds,ax



mov cx,8

mov dx, offset message		; print prompt
mov ah,09h
int 21h

again:
	

	mov dx, offset input		; take input string
    	mov ah, 0Ah
    	int 21h 
  
	
	mov si, offset input+2
	mov cl, input[1]
	cmp cl,0			; if input.length() == 0 then again
	je again

	

	

check:
	
	mov al,[si]

	cmp al, '0'		; if [si]<0 than jump to error
	jb e

	cmp al, '9'
	jbe valid

	cmp al, 'a'		; if [si] => a then jump to error
	jae e

	cmp al, 'A'		; if [si]< A than jump to error
	jb e
	
	cmp al, 'F'		; if [si]=> G than jump to error
	ja e

	

valid:

	inc si
	dec cl
	jnz check
	
	mov dx, offset newline
    	mov ah, 09h
    	int 21h

    	mov dx, offset ans
    	mov ah, 09h
    	int 21h

mov bh, input[1]
mov si,offset input + 2

conversion:
	mov al,[si]
	
	cmp al,'9'
	jbe digit
	
	sub al,'A'
	add al,10
	jmp store
	
digit:
	sub al, '0'

store:
	mov bl,al
	mov cx, 4	

bits:
	shl bl,1
	jc one
	mov dl,'0'

	jmp output
	

one:
	mov dl,'1'
output:
	mov ah, 02h
	int 21h
	loop bits

	inc si
	dec bh
	jnz conversion
	jmp exit


	
e:
	mov dx, offset newline		; new line
	mov ah, 09h
	int 21h

	mov dx, offset error
	mov ah, 09h
	int 21h



	jmp again


exit:
	mov ah,4ch
	int 21h
	main endp
	end main


