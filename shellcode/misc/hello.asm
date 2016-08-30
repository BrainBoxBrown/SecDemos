	xor ebx, 1
	xor edx, 16
	push edx 	; push null to terminate the string
	push "n/sh" ;"/bin/./../bin/sh" streted out to fit 32 bit width stack
	push "./bi"
	push "/./."
	push "/bin"
	mov ecx, esp
	mov al, 0x4
	int 0x80

	xor eax, eax
	inc eax
	int 0x80
