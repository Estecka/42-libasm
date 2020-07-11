section .text
	global ft_write

	ft_write:
		push rbx; Back up callee-saved register.

		mov eax, 4; SYS_WRITE
		mov ebx, edi; fd
		mov rcx, rsi; buffer
		;mov dword rdx, rdx; count
		int 0x80;

		pop rbx; Restore callee-saved register.
		ret;
