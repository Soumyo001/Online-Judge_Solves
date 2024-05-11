;for equation A=A+3B-3C,WHERE C=1
.model small
.stack 100h
.data
c db 3
var1 db ?
space db ' $'
.code
main proc
    
    mov ax,@data
    mov ds,ax
     
    mov ah,1
    int 21h
    mov bl,al
    sub bl,48
    
    mov ah,9
    lea dx,space
    int 21h

    mov ah,1
    int 21h
    mov bh,al
    sub bh,48

    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h

    add bl,bh
    add bl,bh
    add bl,bh
    sub bl,c
    add bl,48

    mov ah,2
    mov dl,bl
    int 21h

    mov ah,4ch
    int 21h
    main endp
end main