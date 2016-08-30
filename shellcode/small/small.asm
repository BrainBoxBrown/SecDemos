global _start
_start:
;xor	eax, eax

jmp short string
code:

; store pointer to /bin/sh in ebx
pop		ebx

mov		al, 0xb ; execve
int 	0x80


string:
call code
db	'/bin/sh', 0x0
