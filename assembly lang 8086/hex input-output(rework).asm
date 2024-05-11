.model small
.stack 100h
.data
.code
main proc

mov ax,@data
mov ds,ax

call hex_input

mov ah, 2
mov dl, 10
int 21h
mov dl, 13
int 21h

call hex_output



mov ah,4ch
int 21h
main endp

hex_input proc
mov bx,0
mov ah,1
mov cl,4
for1:
int 21h
cmp al, 13
je end_for1
cmp al,65
jge letter
digit:
sub al,48
jmp shift
letter:
sub al,55
shift:
shl bx,cl
or bl,al
jmp for1
end_for1:

ret

hex_input endp

hex_output proc

for2:
mov dl,bh
shr dl, 4
shl bx, 4
cmp dl, 10
jge letter2
digit2:
add dl, 48
int 21h
jmp end_for2
letter2:
add dl, 55
int 21h
end_for2:
loop for2

ret

hex_output endp

end main