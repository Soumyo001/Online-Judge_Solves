.model small
.stack 100h
.data
wrong db 10,13,'wrong expression, try again : $'
right db 10,13,'Expression Right $'
wrongBracket db 10,13,'Too many left brackets $'
tryAgain db 10,13,'try again ? $'
count1 db 0
.code
main proc

mov ax, @data
mov ds, ax
start:
xor ax,ax
xor bx,bx

for1:
mov ah,1
int 21h
cmp al,13
je end_for1
cmp al,'('
je pushBracket 
cmp al,'{'
je pushBracket
cmp al,'['
je pushBracket
cmp al,')'
je popBracket1
cmp al,'}'
je popBracket2
cmp al,']'
je popBracket3
jmp for1

pushBracket:
push ax
inc count1
jmp for1

popBracket1:
pop bx
cmp bl, '('
je decreaseCount1
jmp wrongInput
popBracket2:
pop bx
cmp bl, '{'
je decreaseCount1
jmp wrongInput
popBracket3:
pop bx
cmp bl,'['
je decreaseCount1
jmp wrongInput


decreaseCount1:
dec count1
jmp for1

wrongInput:

mov ah,9
lea dx,wrong
int 21h

mov cl,count1
mov count1,0

for2:
pop bx
xor bx,bx
loop for2

jmp for1
end_for1:

mov ah,2
mov dl, 10
int 21h
mov dl, 13
int 21h

xor dx,dx

mov ah,9
cmp count1,0
jne notcorrect
correct:
lea dx,right
int 21h
jmp start_over
notcorrect:
lea dx,wrongBracket
int 21h
start_over:
lea dx,tryAgain
int 21h
mov ah,1
int 21h
cmp al,'y'


exit:
mov ah,4ch
int 21h
main endp
end main