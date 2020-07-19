extern ft_errno

section .text
	global ft_read

	ft_read:
		push rbx; Back up callee-saved register.

		mov rax, 3; SYS_READ
		mov rbx, rdi; fd
		mov rcx, rsi; buffer
		;mov dword rdx, rdx; count
		int 0x80;

		pop rbx; Restore callee-saved register.

		cmp rax, 0;
		jge end; Sets errno if rvalue is negative
		call ft_errno

		end:
		ret;
