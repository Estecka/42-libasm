default rel

section	.data
	message db "Hellow world !", 0xd, 0xa, 0x0
	msglen equ $ - message

section	.text
	global _ft_helloworld

	_ft_helloworld:
		mov rax, 0x2000004 ;set SYS_WRITE into a register
		mov rdi, 1 ;set the file descriptor into a register
		lea rsi, [message] ;set the string into a register (?)
		mov rdx, msglen ;set the string's length into a register
		syscall

		ret
