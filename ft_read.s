section .text
	global ft_read

	ft_read:
		push rbx; Back up callee-saved register.

		mov eax, 3; SYS_READ
		mov ebx, edi; fd
		mov rcx, rsi; buffer
		;mov dword rdx, rdx; count
		int 0x80;

		pop rbx; Restore callee-saved register.
		ret;
