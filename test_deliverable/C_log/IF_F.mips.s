
test_deliverable/C_log/IF_F.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <testif_f>:
  400110:	27bdffd0 	addiu	sp,sp,-48
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080000 	li	t0,0
  40011c:	afa8002c 	sw	t0,44(sp)
  400120:	8fa8002c 	lw	t0,44(sp)
  400124:	00000000 	nop
  400128:	11000008 	beqz	t0,40014c <ifEnd_0_testif_f>
  40012c:	00000000 	nop
  400130:	24080015 	li	t0,21
  400134:	afa80020 	sw	t0,32(sp)
  400138:	8fa80020 	lw	t0,32(sp)
  40013c:	00000000 	nop
  400140:	01001025 	move	v0,t0
  400144:	10000008 	b	400168 <EXIT_testif_f>
  400148:	00000000 	nop

0040014c <ifEnd_0_testif_f>:
  40014c:	24080006 	li	t0,6
  400150:	afa80028 	sw	t0,40(sp)
  400154:	8fa80028 	lw	t0,40(sp)
  400158:	00000000 	nop
  40015c:	01001025 	move	v0,t0
  400160:	10000001 	b	400168 <EXIT_testif_f>
  400164:	00000000 	nop

00400168 <EXIT_testif_f>:
  400168:	8fbf0014 	lw	ra,20(sp)
  40016c:	27bd0030 	addiu	sp,sp,48
  400170:	03e00008 	jr	ra
  400174:	00000000 	nop
	...
