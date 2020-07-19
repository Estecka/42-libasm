extern __errno_location

section .text

	global ft_errno

	;rax errcode
	ft_errno:
		neg rax; Sets the errcode to positive
		mov rdi, rax; Move the errcode away from return value.
		call __errno_location; Get errno location.
		mov [rax], rdi; Set the errcode into errno.
		mov rax, -1; return value is -1
		ret;
