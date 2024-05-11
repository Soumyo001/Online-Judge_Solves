.model small
.stack 100H
.data
str1 db 80 dup('$')
str2 db 80 dup('$')
newLine db 10,13
error db 'Not equal length $'
max db 0
.code
main proc
start:
mov ax, @data
mov ds, ax
mov es, ax

CLD

lea si, str1
lea di, str2
xor cx, cx
mov ah,1

input:
int 21h
cmp al, 13
je end_input
sub al, 48
mov [si], al
inc si
inc cl
jmp input
end_input:

mov max, cl
xor cx, cx


input1:
int 21h
cmp al, 13
je end_input1
sub al, 48
mov [di], al
inc di
inc cl
jmp input1
end_input1:

mov ah, 9
lea dx, newLine
int 21H



lea si, str1
lea di, str2
xor dx, dx
xor ax, ax

for:
mov al, [di]
cmp [si], al
jne equal
unequal:
jmp end_for
equal:
inc dl
end_for:
inc si
inc di
loop for

mov ah, 2
add dl, 48
int 21H
jmp exit

errorShow:
mov ah, 9
lea dx, error
int 21H
jmp start

exit:
mov ah, 4ch
int 21h
main endp 
end main