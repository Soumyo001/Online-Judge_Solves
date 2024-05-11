.model small
.stack 100h
.data
a db ?
b db ?
msg1 db 'Enter 4 numbers sequentially: $'
space db ' $'
.code
main proc
     
    mov ax,@data
    mov ds,ax  ;data initialization

    mov ah,9
    lea dx,msg1
    int 21h

    mov ah,1
    int 21h
    mov bl,al

    mov ah,9
    lea dx,space
    int 21h

    mov ah,1
    int 21h
    mov bh,al

    mov ah,9
    lea dx,space
    int 21h

    mov ah,1
    int 21h
    mov cl,al

    mov ah,9
    lea dx,space
    int 21h

    mov ah,1
    int 21h
    mov ch,al

    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h

    add bl,bh
    sub bl,48
    ;mov a,bl

    add bl,cl
    sub bl,48
    ;mov bl,a

    add bl,ch
    sub bl,48
    ;mov b,bl

    mov ah,2
    mov dl,bl
    int 21h

    mov ah,4ch
    int 21h
    main endp
end main
