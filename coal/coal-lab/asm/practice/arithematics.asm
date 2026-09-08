[org 0x100]

;mov ax,[num]          ; ax = 5
;mov [num+6],ax        ; num ---> 5,10,15,5
;mov ax, [num + 2]     ; ax = 10
;add [num+6], ax       ; num ----> 5,10,15,15
;mov ax, [num+4]       ; ax= = 15
;add [num +6], ax      ; num ----> 5,10,15,30

;int ax, 4c00h
;int 21h

mov ax,[num]          ; ax = 050A
mov [result],ax        ; num ---> 5,10,15,5
mov ax, [num + 2]     ; ax = 10
add [result], ax       ; num ----> 5,10,15,15
mov ax, [num+4]       ; ax= = 15
add [result], ax      ; num ----> 5,10,15,30

num: dw 5,10,15   ;---->    05 0A 0F 00
result : dw 0