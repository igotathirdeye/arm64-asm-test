.global _start
.extern menu

.section .text
_start:

	// print
    mov x0, #1
    ldr x1, =msg
    mov x2, #len
    mov x8, 64
    svc 0

	bl setup
	mov x8, 93
	svc 0
.section .rodata
msg:
	.ascii "Hello, World!\n"
	len = . - msg