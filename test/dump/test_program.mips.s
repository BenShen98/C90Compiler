
test/dump/test_program.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <f>:
10000000:	27bdfff8 	addiu	sp,sp,-8
10000004:	afbe0004 	sw	s8,4(sp)
10000008:	03a0f025 	move	s8,sp
1000000c:	2402000a 	li	v0,10
10000010:	03c0e825 	move	sp,s8
10000014:	8fbe0004 	lw	s8,4(sp)
10000018:	27bd0008 	addiu	sp,sp,8
1000001c:	03e00008 	jr	ra
10000020:	00000000 	nop
	...
