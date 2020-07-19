extern ft_errno

section .text
	global ft_read

	ft_read:
		mov rax, 0; SYS_READ
		;mov rdi, rdi; fd
		;mov rsi, rsi; buffer
		;mov rdx, rdx; count
		syscall;

		cmp rax, 0;
		jge end; Sets errno if rvalue is negative
		call ft_errno

		end:
		ret;
