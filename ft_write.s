extern ft_errno

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

		cmp rax, 0;
		jge end; sets errno if rvalue is negative
		call ft_errno

		end:
		ret;
