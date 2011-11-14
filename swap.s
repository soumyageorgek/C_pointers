	.file	"swap.c"
	.text
.globl swap
	.type	swap, @function
swap:
	subl	$16, %esp
	movl	$1, (%esp)
	movl	20(%esp), %eax
	movl	%eax, 48(%esp)
	movl	24(%esp), %eax
	movl	%eax, 52(%esp)
	addl	$16, %esp
	ret
	.size	swap, .-swap
	.section	.rodata
.LC0:
	.string	"%d %d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$10, 28(%esp)
	movl	$20, 24(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	swap
	movl	24(%esp), %eax
	movl	%eax, 8(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
