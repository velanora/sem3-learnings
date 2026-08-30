[org 0x100]

mov AX, 10
mov BX, 20
mov CX, 30
mov DX, 40
add AX,BX
add AX,CX
add AX,DX

mov AX, 0x4c00
INT 0x21