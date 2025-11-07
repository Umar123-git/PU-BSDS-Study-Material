.model small
.stack 100h
.data
    newline db 13,10,'$'   

.code

main proc
    mov ax, @data
    mov ds, ax             

    call fbin              
    mov bx, 0000           
    call fhex             

exit:
    mov ah, 4Ch
    int 21h                
main endp


fbin proc
    mov cx, 16           
    mov bx, 0             

read_loop:
    mov ah, 01h           
    int 21h
    sub al, 30h           
    shl bx, 1             
    or bx, al              
    dec cx
    jnz read_loop

    

display_decimal:
    mov ax, bx            
    mov cx, 0            

   
    dec_loop:
        xor dx, dx        
        mov bx, 10
        div bx           
        push dx          
        inc cx          
        cmp ax, 0
        jne dec_loop


    print_loop:
        pop dx            
        add dl, 30h       
        mov ah, 02h
        int 21h
        loop print_loop


    mov ah, 09h
    lea dx, newline
    int 21h

    ret
fbin endp


fhex proc
    mov cx, 4             

hex_loop:
    rol bx, 4             
    mov dl, bl
    and dl, 0Fh           

    cmp dl, 09h
    ja hex_letter
    add dl, 30h            
    jmp hex_print

hex_letter:
    add dl, 37h            

hex_print:
    mov ah, 02h
    int 21h
    dec cx
    jnz hex_loop

    ; Print newline
    mov ah, 09h
    lea dx, newline
    int 21h

    ret
fhex endp
end main