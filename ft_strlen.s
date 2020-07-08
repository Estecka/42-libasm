section .text
	global ft_strlen

	ft_strlen:
		mov rax, 0; Initialize a counter/return value.
		mov rcx, rdi; Moves the 1st argument into a register

		compare:
		cmp byte [rcx], 0; Compare the current character with 0
		je 	end; exit if the null terminator was reached
		inc rax; increment the counter
		inc rcx; increment the cursor
		jmp compare; Do another loop

		end:
		ret