.model small
.stack 100h
.data
a db ?
b db ?
input db 'Input Only Uppercase characters: $'
.code
main proc
    
    mov ax,@data
    mov ds,ax

    mov ah,9
    lea dx,input
    int 21h

    mov ah,1
    int 21h
    mov bl,al

    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h

    add bl,32

    mov ah,2
    mov dl,bl
    int 21h

    mov ah,4ch
    int 21h
    main endp
end main