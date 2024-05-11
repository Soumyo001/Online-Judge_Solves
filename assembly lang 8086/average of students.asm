.model small
.stack 100H
.data
    average dw 4 dup (0)
    class   DB  'MARY ALLEN  ',67,45,98,33
            DB  'SCOTT BAYLIS',70,56,87,44
            DB  'GEOGRE FRANK',82,72,89,40
            DB  'SAM WNOG    ',78,76,92,60 
.code
main proc
mov ax, @data
mov ds, ax

lea si, class
lea di, average
mov cx, 4

avg_count:
add si, 12
xor ax, ax ; sum=0
mov dx, 4
sum:
xor bh, bh
mov bl, [si] 
add ax, bx  ; sum+=arr[si]
inc si
dec dx  ; i --
jnz sum

mov bx, 4
div bx

mov [di], ax
add di, 2

loop avg_count

mov cx, 4
lea di, average


rpt:
xor ax, ax
mov ax, [di]
call decimal_output
mov ah, 2
mov dl, ' '
int 21h
add di, 2
loop rpt

mov ah, 4ch
int 21h
main endp
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

mov ah, 2

for1:
pop dx
add dx, 48
int 21h
loop for1

pop dx
pop cx
pop bx
ret
decimal_output endp

end main