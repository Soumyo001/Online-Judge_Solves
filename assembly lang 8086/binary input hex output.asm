.model small
.stack 100h
.data
.code
main proc

mov ax, @data
mov ds, ax


mov bx,0

mov ah,1
 for1:
int 21h
cmp al,13
je end_for1
shl bx,1
sub al,48
or bl,al
jmp for1
end_for1:

mov ah,2 
mov dl,10
int 21h
mov dl,13
int 21h
mov dl,bl
add dl,65
int 21h
mov dl,10
int 21h
mov dl,13
int 21h

mov cx,4

for2:
mov dl,bh
shr dl,4
shl bx,4
cmp dl,10
jge letter
digit:
add dl,48
int 21h
jmp end_for2
letter:
add dl,55
int 21h        
end_for2:
loop for2

mov ah,4ch
int 21h
main endp

binary_input proc




binary_input endp


end main