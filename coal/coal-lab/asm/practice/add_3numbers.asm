[org] 0x100

mov ax, [num1] ; reading value from address which has label num1
mov bx, [num2]      ; [num1 + 2]
add ax, bx
mov bx, [num3]    ; [num1 + 4]
add ax, bx
mov [num4], ax :; writing value from address which has label num4

int ax, 4c00h
int 21h


;num1 : dw 5
;num2 : dw 10
;num3 : dw 15
;num4 : dw 20