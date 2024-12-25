org 100h
.model  tiny
.code
ORG     100h
begin:       	
MOV AL, 2        
MOV BL, 3    
ADD AL,BL         
AAA           
add ax,3030h 
mov dl,ah 
mov dh,al 
mov ah,02 
int 21h 
mov dl,dh 
int 21h
end begin
ret