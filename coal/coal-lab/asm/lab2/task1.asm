[org 0x100]

mov AX,6
mov BX,6
add BX, AX
add BX, AX
add BX, AX
add BX, AX
add BX, AX

mov AX, 0x4c00
INT 0x21
