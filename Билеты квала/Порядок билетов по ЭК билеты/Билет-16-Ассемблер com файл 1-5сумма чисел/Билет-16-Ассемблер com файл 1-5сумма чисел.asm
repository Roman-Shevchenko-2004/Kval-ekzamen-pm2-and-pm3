.model tiny
org 100h
begin:
mov cx,5
mov bx,0
metka:
mov ah,1h
int 21h
sub al,'0'
add bx,ax
aaa
loop metka
mov ah, 2h
mov dl,' '
int 21h
mov ah,2h
add bx,'0'
mov ah,2h
mov dx,bx
int 21h
mov ah,4ch
int 21h
end begin
ret