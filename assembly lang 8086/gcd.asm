.model small
.stack 100h
.data
.code
main proc

mov ax, @data
mov ds, ax

mov ah, 1
int 21h
sub al,48
xor ah,ah
mov bx,ax 
xor ax,ax
mov ah,1
int 21h 
sub al,48
xor ah,ah
xchg ax,bx
  
for1:   
xor dx,dx
div bx

cmp dx,0
je end_for1


mov ax,bx;m   
mov bx,dx;n 


jmp for1

end_for1:

xor ah,ah
mov ah,2
mov dl,10
int 21h
mov dl,13
int 21h
mov dl,bl
add dl,48
int 21h




mov ah,4ch
int 21h
main endp
end main  


;mov ah,2
;mov dl,al
;add dl,48 
;int 21h
;mov dl,bl
;add dl,48
;int 21h
;mov dl,10
;int 21h
;mov dl,13
;int 21h  
;xor ah,ah


;mov ah,2
;mov dl,al
;add dl,48
;int 21h
;mov dl,bl
;add dl,48
;int 21h