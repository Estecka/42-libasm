extern malloc
extern ft_strlen
extern ft_strcpy

section .text
	global ft_strdup

	ft_strdup:
		mov rbx, rdi; Saves 1st arg into a callee-safe register.
		call ft_strlen; Gets the lenght of src.
		inc rax; Make space for the null-terminator.

		mov rax, rdi; Arg#1 len
		call malloc;

		cmp rax, 0; Checks whether mallocation failed.
		je  end; Aborts if so.

		mov rdi, rax; Arg#1 dst
		mov rsi, rbx; Arg#2 src
		call ft_strcpy;

		end:
		ret
