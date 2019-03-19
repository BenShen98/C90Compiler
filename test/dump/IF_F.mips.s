
test/dump/IF_F.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <testnif>:
10000000:	27bdfff8 	addiu	sp,sp,-8
10000004:	afbe0004 	sw	s8,4(sp)
10000008:	03a0f025 	move	s8,sp
1000000c:	afc40008 	sw	a0,8(s8)
10000010:	8fc20008 	lw	v0,8(s8)
10000014:	28420005 	slti	v0,v0,5
10000018:	14400004 	bnez	v0,1000002c <testnif+0x2c>
1000001c:	00000000 	nop
10000020:	24020003 	li	v0,3
10000024:	10000002 	b	10000030 <testnif+0x30>
10000028:	00000000 	nop
1000002c:	24020001 	li	v0,1
10000030:	03c0e825 	move	sp,s8
10000034:	8fbe0004 	lw	s8,4(sp)
10000038:	27bd0008 	addiu	sp,sp,8
1000003c:	03e00008 	jr	ra
10000040:	00000000 	nop
	...
