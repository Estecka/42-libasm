extern ft_errno

section .text
	global ft_write

	ft_write:
		mov rax, 1; SYS_WRITE
		;mov rdi, rdi; fd
		;mov rsi, rsi; buffer
		;mov rdx, rdx; count
		syscall;

		cmp rax, 0;
		jge end; sets errno if rvalue is negative
		call ft_errno

		end:
		ret;
