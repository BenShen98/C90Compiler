
test_deliverable/C_log/logicalOr.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <f>:
  400110:	27bdffc8 	addiu	sp,sp,-56
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	8fa80034 	lw	t0,52(sp)
  40011c:	00000000 	nop
  400120:	24090003 	li	t1,3
  400124:	240a0002 	li	t2,2
  400128:	0149582a 	slt	t3,t2,t1
  40012c:	1560000a 	bnez	t3,400158 <ORShort_0_f>
  400130:	00000000 	nop
  400134:	24090003 	li	t1,3
  400138:	240a0002 	li	t2,2
  40013c:	012a602a 	slt	t4,t1,t2
  400140:	15800005 	bnez	t4,400158 <ORShort_0_f>
  400144:	00000000 	nop
  400148:	00004025 	move	t0,zero
  40014c:	afa80034 	sw	t0,52(sp)
  400150:	10000003 	b	400160 <OREnd_1_f>
  400154:	00000000 	nop

00400158 <ORShort_0_f>:
  400158:	24080001 	li	t0,1
  40015c:	afa80034 	sw	t0,52(sp)

00400160 <OREnd_1_f>:
  400160:	afab0028 	sw	t3,40(sp)
  400164:	afac001c 	sw	t4,28(sp)
  400168:	8fa80034 	lw	t0,52(sp)
  40016c:	00000000 	nop
  400170:	01001025 	move	v0,t0
  400174:	10000001 	b	40017c <EXIT_f>
  400178:	00000000 	nop

0040017c <EXIT_f>:
  40017c:	8fbf0014 	lw	ra,20(sp)
  400180:	27bd0038 	addiu	sp,sp,56
  400184:	03e00008 	jr	ra
  400188:	00000000 	nop
  40018c:	00000000 	nop
