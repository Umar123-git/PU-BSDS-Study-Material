.model small
.stack 100h
.data

arr db 16,5,2,8,12,7,3,9,1,4,10,6,15,11,14,13
msg db "Sorted Array (Hex): $"

.code
main proc
    mov ax,@data
    mov ds,ax

    mov cx,16
outer_loop:
    push cx
    mov si,0
    mov bx,15
inner_loop:
    mov al,arr[si]
    mov dl,arr[si+1]
    cmp al,dl
    jbe no_swap
    mov arr[si],dl
    mov arr[si+1],al
no_swap:
    inc si
    dec bx
    jnz inner_loop
    pop cx
    dec cx
    jnz outer_loop

    mov dx,offset msg
    mov ah,09h
    int 21h

    mov cx,16
    mov si,0
print_loop:
    mov bl,arr[si]
    mov al,bl
    shr al,1
    shr al,1
    shr al,1
    shr al,1
    cmp al,9
    jbe d1
    add al,7
d1:
    add al,30h
    mov dl,al
    mov ah,02h
    int 21h

    mov al,bl
    and al,0Fh
    cmp al,9
    jbe d2
    add al,7
d2:
    add al,30h
    mov dl,al
    mov ah,02h
    int 21h

    mov dl,' '
    mov ah,02h
    int 21h

    inc si
    dec cx
    jnz print_loop

    mov ah,4Ch
    int 21h
main endp
end main