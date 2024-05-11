.model small
.stack 100h
.data
N db ?
.code
main proc
    mov ax,@data
    mov ds,ax

    mov ah,1
    int 21h
    sub al,48
    mov N,al

    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h

    mov dl,'*'
    mov bl,1
    mov cl,N

    for1:
      cmp bl,N
      jg end_for1
      mov dl,'*'
      mov bh,1
        for2:
          cmp bh,cl
          jg end_for2
          int 21h
          inc bh
          jmp for2
        end_for2:
        mov dl,10
        int 21h
        mov dl,13
        int 21h
        inc bl
        dec cl
        jmp for1
    end_for1:




    mov ah,4ch
    int 21h
    main endp
end main