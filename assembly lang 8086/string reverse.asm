.model small
.stack 100h
.data
.code
main proc
  
mov ax,@data
mov ds,ax

mov ah,1
mov cx,0
for1:
int 21h
cmp al,13
je end_for1
push ax
inc cx
jmp for1
end_for1:

mov ah,2
mov dl,10
int 21h
mov dl,13
int 21h
mov dl,0

for2:
pop dx
xor dh,dh
int 21h
loop for2


exit:
mov ah,4ch
int 21h
main endp



end main