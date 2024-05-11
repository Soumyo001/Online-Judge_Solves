.model small
.stack 100h
.data
wrong db 10,13,'Input Correct Data :',10,13,'$'
count db 0
.code
main proc 

mov ax, @data
mov ds, ax
start:

mov bx,0
mov ah,1
mov count,0


for1:
int 21h
cmp al,13
je end_for1
cmp al,48
jl error
cmp al,49
jg error
shl bx,1
sub al,48
or bl,al
inc count
jmp for1
end_for1:

mov cl,16
sub cl,count
rcl bx,cl
mov cl,count
mov ah,2
mov dl,10
int 21h
mov dl,13
int 21h


for2:
rcl bx,1
jc one
zero:
mov dl,'0'
int 21h
jmp end_for2
one:
mov dl,'1'
int 21h
end_for2:
loop for2
jmp exit


error:
mov ah,9
lea dx,wrong
int 21h
jmp start


exit:
mov ah,4ch
int 21h
main endp
end main