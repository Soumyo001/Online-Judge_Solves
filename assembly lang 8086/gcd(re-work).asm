.model small
.stack 100h
.data
N db 0
count db 0
n1 db 0
n2 db 0 
digits db 0
gcd dw 0
.code
main proc

mov ax, @data
mov ds, ax

xor dx,dx
xor cx,cx

mov N, 0
call decimal_input
mov n1, dl

xor dl, dl
mov N, 0
call decimal_input
mov n2, dl

mov al, n1
mov bl, n2
xor ah, ah
xor bh, bh 

for1:
xor dx, dx
div bx
cmp dx, 0
je end_for1

mov ax, bx ;
mov bx, dx ;n
jmp for1

end_for1:

mov gcd, bx

xor ah, ah
mov ah, 2
mov dl, 10
int 21h
mov dl, 13
int 21h

xor ax, ax
mov ax, gcd

call decimal_output

mov ah,4ch
int 21h
main endp

decimal_input proc
for:
mov ah, 1
xor al, al
int 21h

cmp al, 13
je end_for

sub al, 48
mov N, al
mov al, 10
mul dl
add al, N
mov dl, al
jmp for

end_for:

ret
decimal_input endp

decimal_output proc

push bx
push cx
push dx

xor cx, cx
mov bx, 10

for2:
xor dx, dx
div bx
push dx
inc cx
or ax, ax
jne for2

mov ah, 2

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