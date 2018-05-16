	.file	"sigaction.c"
	.local	env
	.comm	env,156,32
	.local	flag
	.comm	flag,4,4
	.section	.rodata
.LC0:
	.string	"flag:%d\n"
	.text
	.globl	sigHandler
	.type	sigHandler, @function
sigHandler:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	$0, -12(%ebp)
	jmp	.L2
.L3:
	addl	$1, -12(%ebp)
.L2:
	cmpl	$999999999, -12(%ebp)
	jle	.L3
	movl	flag, %eax
	leal	1(%eax), %edx
	movl	%edx, flag
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	sigHandler, .-sigHandler
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$160, %esp
	movl	$sigHandler, 20(%esp)
	leal	20(%esp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	sigemptyset
	movl	$0, 152(%esp)
	movl	$0, 156(%esp)
	movl	$0, 8(%esp)
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	sigaction
	movl	$0, 8(%esp)
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$3, (%esp)
	call	sigaction
.L6:
	call	pause
	jmp	.L6
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.4) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
