.model small
.stack 100h
.data
number dw 65,66,67,68,69,70,71
number1 db 4,5,6,4 dup(2,3 dup(4))
number3 db 10 DUP(?)
number4 dw 1 dup(3 dup(2 dup(3 dup (5))), 4 dup(4))
.code
main proc

mov ax,@data
mov ds,ax

mov cx,19
mov ah,2
mov bx,0
; print array using indexing mode and register indirect mode
for1:
mov dl,number1[bx]
add dl,48
int 21h
mov dl,' '
int 21h
inc bx
loop for1

mov dl,10
int 21h
mov dl,13
int 21h

lea si,number
mov cx,7
for2:
mov dl,[si]
;add dl,48
int 21h
mov dl,' '
int 21h
add si,2
loop for2

mov dl, 10
int 21h
mov dl, 13
int 21h

mov ah,1
mov cx,10
mov bx,0

; take input in number 3 array by indexing mode and display it in register indirect mode
for3:
int 21h
mov number3[bx],al
inc bx
loop for3

mov ah,2
mov cx,10
lea si,number3
mov dl,10
int 21h
mov dl, 13
int 21h

for4:
mov dl,[si]
int 21h
mov dl,' '
int 21h
inc si
loop for4


mov dl, 10
int 21h
mov dl, 13
int 21h
;take input in nested dup and display

mov cx,22
lea si,number4
mov ah,1
for5:
int 21h
mov [si],al
add si,2
loop for5

mov ah,2
mov dl, 10
int 21h
mov dl, 13
int 21h

mov cx,22
mov bx,0
for6:
mov dx,number4[bx]
int 21h
mov dl,' '
int 21h
add bx,2
loop for6



mov ah,4ch
int 21h
main endp
end main