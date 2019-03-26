
test_deliverable/C_log/while.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <testwhile>:
  400110:	27bdffd8 	addiu	sp,sp,-40
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080002 	li	t0,2
  40011c:	afa80020 	sw	t0,32(sp)
  400120:	8fa80020 	lw	t0,32(sp)
  400124:	00000000 	nop
  400128:	afa80024 	sw	t0,36(sp)

0040012c <ItrCondition_0_testwhile>:
  40012c:	8fa80024 	lw	t0,36(sp)
  400130:	00000000 	nop
  400134:	11000007 	beqz	t0,400154 <ItrEnd_1_testwhile>
  400138:	00000000 	nop
  40013c:	8fa80024 	lw	t0,36(sp)
  400140:	00000000 	nop
  400144:	2108ffff 	addi	t0,t0,-1
  400148:	afa80024 	sw	t0,36(sp)

0040014c <conti_2_testwhile>:
  40014c:	1000fff7 	b	40012c <ItrCondition_0_testwhile>
  400150:	00000000 	nop

00400154 <ItrEnd_1_testwhile>:
  400154:	8fa80024 	lw	t0,36(sp)
  400158:	00000000 	nop
  40015c:	01001025 	move	v0,t0
  400160:	10000001 	b	400168 <EXIT_testwhile>
  400164:	00000000 	nop

00400168 <EXIT_testwhile>:
  400168:	8fbf0014 	lw	ra,20(sp)
  40016c:	27bd0028 	addiu	sp,sp,40
  400170:	03e00008 	jr	ra
  400174:	00000000 	nop
	...
