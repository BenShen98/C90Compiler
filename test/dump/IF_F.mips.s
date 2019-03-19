
test/dump/IF_F.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <testnif>:
  400110:	27bdfff8 	addiu	sp,sp,-8
  400114:	afbe0004 	sw	s8,4(sp)
  400118:	03a0f025 	move	s8,sp
  40011c:	afc40008 	sw	a0,8(s8)
  400120:	8fc20008 	lw	v0,8(s8)
  400124:	28420005 	slti	v0,v0,5
  400128:	14400004 	bnez	v0,40013c <testnif+0x2c>
  40012c:	00000000 	nop
  400130:	24020003 	li	v0,3
  400134:	10000002 	b	400140 <testnif+0x30>
  400138:	00000000 	nop
  40013c:	24020001 	li	v0,1
  400140:	03c0e825 	move	sp,s8
  400144:	8fbe0004 	lw	s8,4(sp)
  400148:	27bd0008 	addiu	sp,sp,8
  40014c:	03e00008 	jr	ra
  400150:	00000000 	nop
	...
