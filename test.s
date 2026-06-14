.global _start

.section .text
_start:

	// print
    mov x0, #1
    ldr x1, =msg
    mov x2, #len
    mov x8, 64
    svc 0

	// returns 0 (success)
	mov x0, 0

	mov x8, 93
	svc 0
.section .rodata
msg:
	.ascii "Hello, World!\n"
	len = . - msg
