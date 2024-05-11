.model small
.stack 100h
.data
.code
main proc

mov ax,@data
mov ds,ax

  
mov ah,1
int 21h
sub al,48
mov bl,al   

 mov ah,2
 mov dl,10
 int 21h
 mov dl,13
 int 21h

mov ah,1
int 21h
sub al,48
mov cl,al

mov ah,2
mov dl,10
int 21h
mov dl,13
int 21h


call multiply


mov ah,4ch
int 21h
main endp 


multiply proc

   xor dl,dl
   for1:
    cmp cl,0
    je end_for1
    shr cl,1
    jnc zero
    one:
    add dl,bl
    zero:
    shl bl,1
    jmp for1
   end_for1:
    
    add dl,48
    int 21h
    
    ret
multiply endp



end main