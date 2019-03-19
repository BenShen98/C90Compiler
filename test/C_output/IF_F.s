	.file	1 "IF_F.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=32
	.module	oddspreg
	.abicalls
	.text
	.align	2
	.globl	testnif
	.set	nomips16
	.set	nomicromips
	.ent	testnif
	.type	testnif, @function
testnif:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-8
	sw	$fp,4($sp)
	move	$fp,$sp
	sw	$4,8($fp)
	lw	$2,8($fp)
	slt	$2,$2,5
	bne	$2,$0,$L2
	nop

	li	$2,3			# 0x3
	b	$L3
	nop

$L2:
	li	$2,1			# 0x1
$L3:
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	testnif
	.size	testnif, .-testnif
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
