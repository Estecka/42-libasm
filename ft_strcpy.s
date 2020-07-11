section .text
	global ft_strcpy

	ft_strcpy:
		mov rax, rdi; Sets the return value to dst

		loop:
		mov byte cl, [rsi]; Copies src byte in register.
		mov byte [rdi], cl; Copies register to dst.
		cmp byte [rdi], 0; Checks for null terminator.
		je end; Quits if null terminator.
		inc rdi; Increment dst pointer.
		inc rsi; Increment src pointer.
		jmp loop; Do another loop.

		end:
		ret
