.model small
.stack 100h
.data
number db 10 dup (?)
.code
main proc
mov ax, @data
mov ds, ax

mov cx, 10

mov bx,0

for:
mov ah, 1
int 21h
mov number[bx], al
mov ah, 2
mov dl, ' '
int 21h
inc bx
loop for

lea si, number
mov cx, 10
mov ah, 2
mov dl, 10
int 21h
mov dl, 13
int 21h
for1:
mov dl, [si]
int 21h
mov dl, ' '
int 21h
inc si
loop for1

mov ah, 4ch
int 21h
main endp
end main