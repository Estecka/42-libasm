section .text
	global ft_strcmp

	ft_strcmp:
		mov word rax, 0; Initializes the return value.
		mov word rdx, 0; Initializes a temp int variable.

		loop:
		mov byte al, [rdi]; Copies src char to int return value.
		mov byte dl, [rsi]; Cast dst char to int.
		sub word eax, edx; Perform int substraction on the return value.
		cmp word eax, 0; Exit if bytes are different.
		jne end;
		cmp byte [rdi], 0; Exit if src is ending.
		je  end;
		cmp byte [rsi], 0; Exit if dst is ending.
		je  end;
		inc rdi; Increment src.
		inc rsi; Increment dst.
		jmp loop; Do another loop.

		end:
		ret
