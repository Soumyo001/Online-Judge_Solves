.model small
.stack 100h
.data
N db ?
.code
main proc

mov ax,@data
mov ds,ax

mov ah,1
int 21h
sub al,48
mov N,al


mov ah,2
mov dl,10
int 21h
mov dl,13
int 21h

mov bl,1
mov cl,0

for1:
cmp bl,N
jg end_for1

add cl,bl
inc bl
jmp for1

end_for1:

mov ah,2
mov dl,cl
int 21h
 
exit:
mov ah,4ch
int 21h
main endp
end main