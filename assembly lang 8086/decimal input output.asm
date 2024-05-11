.model small
.stack 100h
.data
N db 0
count db 0 
.code
main proc

mov ax,@data
mov ds,ax

xor cx,cx
xor dx,dx

call decimal_input
mov N,dl 


mov ah,2
mov dl,10
int 21h
mov dl,13 
int 21h

xor ah, ah
mov al, N

call decimal_output

mov ah,4ch
int 21h
main endp

decimal_input proc

for1:
mov ah,1
int 21h
cmp al,13
je end_for1

sub al,48
mov N,al
mov al,10
mul dl
add al,N
mov dl,al
inc count
jmp for1

end_for1:

ret
decimal_input endp  

decimal_output proc
push bx
push cx
push dx

xor cx, cx
mov bx, 10

for:
xor dx, dx
div bx
push dx
inc cx
or ax, ax
jne for

mov ah, 1

print:
pop dx
add dx, 48
int 21h
loop print

pop dx
pop cx
pop bx

ret
decimal_output endp

end main