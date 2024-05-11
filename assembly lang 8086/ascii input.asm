.model small
.stack 100h
.data 
count db 0
.code
main proc 

mov ax, @data
mov ds, ax

mov ah, 1
int 21h
xor bx,bx
mov bl, al

mov cx, 8
mov ah, 2
mov dl, 10
int 21h
mov dl, 13
int 21h

for1:
shl bl, 1
jc one
zero:
mov dl, '0'
int 21h
jmp end_for1
one:
mov dl, '1'
int 21h
end_for1:
loop for1

mov bl,al

mov dl, 10
int 21h
mov dl, 13
int 21h

xor cx,cx
mov cx,8
xor dx,dx

bitCount:
shl bl,1
jnc bitZero
inc dl
bitZero:
loop bitCount

add dl,48
int 21h



mov ah, 4ch
int 21h
main endp
end main