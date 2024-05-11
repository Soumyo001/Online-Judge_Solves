.model small
.stack 100h
.data
a db 3
b db ?
c db 10,13,'Input Your Number ! ',10,13,'$'
.code
main proc
    mov ax,@data
    mov ds,ax

    mov ah,2
    mov dl,a
    int 21h

    mov ah,9
    lea dx,c
    int 21h

    mov ah,2
    ;add a,48
    mov dl,a
    add dl,48
    int 21h

    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h

    mov ah,1
    int 21h
    mov ch,al
    mov b,ch

    mov ah,2
    mov dl,ch
    int 21h

    exit:
    mov ah,4ch
    int 21h
    main endp
end main