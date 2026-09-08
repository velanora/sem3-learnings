[org 0x100]

mov ax, [num1]
mov bx, [num1+1]
add ax, bx

mov bx, [num1+2]
add ax, bx

mov [num1+3], ax
mov ax,4c00h
int 21h

num1: db 5, 10,15, 0