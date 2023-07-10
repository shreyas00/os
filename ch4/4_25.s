	.file	"4_25.c"
	.text
	.comm	points_inside,4,4
	.section	.rodata
.LC1:
	.string	"Pi is %f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, %edi
	call	srand@PLT
	movl	$0, points_inside(%rip)
	movsd	-56(%rbp), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	-48(%rbp), %xmm0
	movsd	%xmm0, -24(%rbp)
	leaq	-32(%rbp), %rax
	movl	$0, %ecx
	movl	$0, %edx
	movq	%rax, %rsi
	leaq	main._omp_fn.0(%rip), %rdi
	call	GOMP_parallel@PLT
	movsd	-32(%rbp), %xmm0
	movsd	%xmm0, -56(%rbp)
	movsd	-24(%rbp), %xmm0
	movsd	%xmm0, -48(%rbp)
	movl	points_inside(%rip), %eax
	sall	$2, %eax
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC0(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %xmm0
	leaq	.LC1(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.type	main._omp_fn.0, @function
main._omp_fn.0:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	call	omp_get_num_threads@PLT
	movl	%eax, %ebx
	call	omp_get_thread_num@PLT
	movl	%eax, %esi
	movl	$50000, %eax
	cltd
	idivl	%ebx
	movl	%eax, %ecx
	movl	$50000, %eax
	cltd
	idivl	%ebx
	movl	%edx, %eax
	cmpl	%eax, %esi
	jl	.L5
.L10:
	imull	%ecx, %esi
	movl	%esi, %edx
	addl	%edx, %eax
	leal	(%rax,%rcx), %ebx
	cmpl	%ebx, %eax
	jge	.L4
	movl	%eax, -20(%rbp)
.L8:
	call	rand@PLT
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	.LC3(%rip), %xmm1
	subsd	%xmm1, %xmm0
	movq	-40(%rbp), %rax
	movsd	%xmm0, (%rax)
	call	rand@PLT
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	.LC3(%rip), %xmm1
	subsd	%xmm1, %xmm0
	movq	-40(%rbp), %rax
	movsd	%xmm0, 8(%rax)
	movq	-40(%rbp), %rax
	movsd	(%rax), %xmm0
	movq	-40(%rbp), %rax
	movsd	(%rax), %xmm1
	mulsd	%xmm0, %xmm1
	movq	-40(%rbp), %rax
	movsd	8(%rax), %xmm0
	movq	-40(%rbp), %rax
	movsd	8(%rax), %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	call	sqrt@PLT
	movsd	.LC3(%rip), %xmm1
	comisd	%xmm0, %xmm1
	jnb	.L7
.L9:
	addl	$1, -20(%rbp)
	cmpl	%ebx, -20(%rbp)
	jl	.L8
	jmp	.L4
.L7:
	movl	points_inside(%rip), %eax
	addl	$1, %eax
	movl	%eax, points_inside(%rip)
	jmp	.L9
.L5:
	movl	$0, %eax
	addl	$1, %ecx
	jmp	.L10
.L4:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main._omp_fn.0, .-main._omp_fn.0
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1088973312
	.align 8
.LC2:
	.long	4290772992
	.long	1104150527
	.align 8
.LC3:
	.long	0
	.long	1072693248
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu2) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
