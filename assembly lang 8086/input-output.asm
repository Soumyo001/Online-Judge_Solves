.model small
.stack 100h
.data
input1 db 'input first number or character: $'
input2 db 'input second number or character: $'
show db 'input values: $'
space db ' $'
.code
main proc

    mov ax,@data ;data initialization
    mov ds,ax

    mov ah,9
    lea dx,input1
    int 21h

    mov ah,1
    int 21h
    mov bl,al

    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h

    mov ah,9
    lea dx,input2
    int 21h

    mov ah,1
    int 21h
    mov bh,al

    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h

    mov ah,9
    lea dx,show
    int 21h

    mov ah,2
    mov dl,bl
    int 21h

    ;mov ah,2
    ;mov dl,10
    ;int 21h
    ;mov dl,13
    ;int 21h

    mov ah,9
    lea dx,space
    int 21h

    mov ah,2
    mov dl,bh
    int 21h
    
    mov ah,4ch
    int 21h
    main endp
end main