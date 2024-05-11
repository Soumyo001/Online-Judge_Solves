.model small
.stack 100H
.data
count db 0
max db 0
flag db 0
string db 'one is here $'
.code
main proc 
mov ax, @data
mov ds, ax

mov ah,1
int 21h
sub al, 48

mov cx, 4

for:
shr al, 1
jc one
zero:
jmp increament

one:
cmp flag, 0
je flag_zero

flag_non_zero:
mov bl, count
cmp bl, max
jge max_update
cmp bl, max
jl end_for

flag_zero:
mov flag, 1
jmp end_for

increament:
inc count
jmp end_for

max_update:
mov max, bl
mov count, 0
mov flag, 0

end_for:
loop for

mov ah,2
mov dl, max
add dl, 48
int 21h

mov ah, 4ch
int 21h
main endp
end main