.model small
.stack 100H
.data
str1 db 80 dup('$')
str2 db 80 dup('$')
isPalindrom db 10,13,'It is palindrome $'
aintPalindrom db 10,13,'It is not palindrome $'
EMPTY DB 10,13,'OPPS !!!! INPUT STRING IS EMPTY $'
.code
main proc
mov ax, @data
mov ds, ax
mov es, ax
CLD

xor cx, cx
lea si, str1
mov ah,1

input:
int 21h
cmp al, 13
je enter_pressed


push ax
inc cx
mov [si], al
inc si
jmp input
enter_pressed:

cmp cx, 0
je error

lea di, str2
mov bx, cx

copy:
pop dx
xor dh, dh
mov [di], dl
inc di
loop copy

lea si, str1
lea di, str2
mov cx, bx
repe cmpsw
jz palindrome


notPalindrome:
mov ah, 9
lea dx, aintPalindrom
int 21h
jmp exit

error:
mov ah, 9
lea dx, EMPTY
int 21h
jmp exit


palindrome:
mov ah, 9
lea dx, isPalindrom
int 21h

exit:
mov ah, 4ch
int 21h
main endp
end main