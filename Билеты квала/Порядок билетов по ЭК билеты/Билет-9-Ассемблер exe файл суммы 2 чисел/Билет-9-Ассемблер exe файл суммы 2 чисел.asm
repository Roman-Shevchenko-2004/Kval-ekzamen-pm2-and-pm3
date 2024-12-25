org 100h
.model tiny
stack segment 100h
code segment
start:
mov al,5
mov bl,4
add al,bl
aaa
add ax,3030h
mov dl,ah
mov dh,al
mov ah,2
int 21h  
mov dl,dh
int 21h    
ends
end start