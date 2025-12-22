.model small
.stack 100h
.data
msg db 0Ah, 0Dh, 'Enter the Cents in between 0 and 99: $'

HD db 0Ah, 0Dh, 'Half Dollars: $'
Q  db 0Ah, 0Dh, 'Quarters: $'
D  db 0Ah, 0Dh, 'Dimes: $'
N  db 0Ah, 0Dh, 'Nickels: $'
P  db 0Ah, 0Dh, 'Pennies: $'

arr db 5 dup(0)

;NEWLINE DB 0Ah, 0Dh, '$'

.code
main proc
mov ax,@data
mov ds,ax



mov si,offset arr

input:    
    mov dx, offset msg
    mov ah,09h
    int 21h
	
	mov ah,01h
	int 21h
	
	sub al,30h
	mov bl, 00
	mov bl,al
	mov ax,0000
	mov ax,10
	mul bl
	mov bl,al
	
	mov ah,01h
	int 21h
	sub al,30h
	add al, bl

	mov si,offset arr
loop_start:
	
	cmp al,50
	jae Half

	
	cmp al, 25
	jae quater
	
	
	cmp al, 10
	jae dime
	
	
	cmp al, 5
	jae Nickel
	
	cmp al,1
	jae penny


	cmp al, 0
	je display
	
	
	
	
	;jmp display
	;jmp exit



Half:
	mov bl,[si]
	inc bl
	mov [si],bl
	sub al,50
	jmp loop_start

quater:
	mov bl,[si+1]
	inc bl
	mov [si+1],bl
	sub al,25
	jmp loop_start

dime:
	mov bl,[si+2]
	inc bl
	mov [si+2],bl
	sub al,10
	jmp loop_start

Nickel:
	mov bl,[si+3]
	inc bl
	mov [si+3],bl
	sub al,5
	jmp loop_start

penny:
	mov bl,[si+4]
	inc bl
	mov [si+4],bl
	sub al,1
	jmp loop_start

	
	
display:
	mov al,0

	mov ah,09h
	mov dx, offset HD
	int 21h
	

	mov dl,[si]
	add dl,30h
	mov ah, 02h
	int 21h
	
	mov ah,09h
	mov dx, offset Q
	int 21h
	

	mov dl,[si+1]
	add dl,30h
	mov ah, 02h
	int 21h
	
	mov ah,09h
	mov dx, offset D
	int 21h
	

	mov dl,[si+2]
	add dl,30h
	mov ah, 02h
	int 21h
	
	mov ah,09h
	mov dx, offset N
	int 21h
	

	mov dl,[si+3]
	add dl,30h
	mov ah, 02h
	int 21h
	
	mov ah,09h
	mov dx, offset P
	int 21h
	

	mov dl,[si+4]
	add dl,30h
	mov ah, 02h
	int 21h

exit:
    mov ah,4ch
    int 21h
main endp
end main


