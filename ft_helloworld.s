section	.data
	message db "Hellow world !", 0xd, 0xa, 0x0
	msglen equ $ - message

section	.text
	global ft_helloworld

	ft_helloworld:
		mov eax, 4 ;set SYS_WRITE into a register
		mov ebx, 1 ;set the file descriptor into a register
		mov ecx, message ;set message into a register (?)
		mov edx, msglen ;set message length into a register
		int 0x80 ;interrupt signal; calls the kernel on the registers.

		ret