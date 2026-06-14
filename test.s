.global _start

_start:
	mov x0, 5

	mov x8, 93
	svc 0
	// this should return 5 i think
