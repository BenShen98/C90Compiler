
beq.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <recadd>:
  400110:	27bdffe8 	addiu	sp,sp,-24
  400114:	afbe0014 	sw	s8,20(sp)
  400118:	03a0f025 	move	s8,sp
  40011c:	8fc30004 	lw	v1,4(s8)
  400120:	8fc20008 	lw	v0,8(s8)
  400124:	00621026 	xor	v0,v1,v0
  400128:	0002102b 	sltu	v0,zero,v0
  40012c:	304200ff 	andi	v0,v0,0xff
  400130:	afc2000c 	sw	v0,12(s8)
  400134:	00000000 	nop
  400138:	03c0e825 	move	sp,s8
  40013c:	8fbe0014 	lw	s8,20(sp)
  400140:	27bd0018 	addiu	sp,sp,24
  400144:	03e00008 	jr	ra
  400148:	00000000 	nop
  40014c:	00000000 	nop
