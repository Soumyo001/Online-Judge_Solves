.model small
.stack 100h
.data
.code
main proc

mov ax,@data
mov ds,ax


mov al,2
mov bl,2
mul bl

mov dl,al
xor al,al
mov ah,2
add dl,48
int 21h

mov dl,10
int 21h
mov dl,13
int 21h  

xor dl,dl

mov ax,9
mov cx,5
div cx    ;dx:ax=ax/cx where dx=remainder and ax=quotient  ;dx:ax (32-bit register pair)

mov bx,ax
mov cx,dx
mov ah,0
mov ah,2
mov dl,cl
add dl,48
int 21h
mov dl,bl
add dl,48
int 21h





mov ah,4ch
int 21h
main endp
end main