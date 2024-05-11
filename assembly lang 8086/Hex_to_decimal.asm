.model small
.stack 100h
.data
a db 10,13,'Enter a Hex Digit : $'
b db 10,13,'Want to try again (Y/N) ? $'
c db 10,13,'Give correct input (0-F) : $'
.code
main proc
   mov ax,@data
   mov ds,ax

   start:
   mov ah,9
   lea dx,a
   int 21h

   start1:
   mov ah,1
   int 21h
   mov bl,al

   mov ah,2
   mov dl,10
   int 21h
   mov dl,13
   int 21h

   cmp bl,'0'
   jb retry
   cmp bl,'9'
   jbe Digitconversion
   cmp bl,'A'
   jb retry
   cmp bl,'F'
   jbe Charconversion
   jmp retry

   Digitconversion:
   mov ah,2
   mov dl,bl
   int 21h

   mov ah,9
   lea dx,b
   int 21h

   mov ah,1
   int 21h
   mov bl,al

   cmp bl,'Y'
   je start
   jmp exit

   Charconversion:
   sub bl,17d
   mov ah,2
   mov dl,49
   int 21h
   mov dl,bl
   int 21h

   mov ah,9
   lea dx,b
   int 21h

   mov ah,1
   int 21h
   mov bl,al

   cmp bl,'Y'
   je start
   jmp exit


   retry:
   mov ah,9
   lea dx,c
   int 21h
   jmp start1

   exit:
   mov ah,4ch
   int 21h
   main endp
end main