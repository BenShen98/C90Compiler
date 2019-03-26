
test_deliverable/C_log/shadowvar.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <f>:
  400110:	27bdffd0 	addiu	sp,sp,-48
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080005 	li	t0,5
  40011c:	afa80028 	sw	t0,40(sp)
  400120:	8fa80028 	lw	t0,40(sp)
  400124:	00000000 	nop
  400128:	afa8002c 	sw	t0,44(sp)
  40012c:	24080006 	li	t0,6
  400130:	afa8001c 	sw	t0,28(sp)
  400134:	8fa8001c 	lw	t0,28(sp)
  400138:	00000000 	nop
  40013c:	8fa8002c 	lw	t0,44(sp)
  400140:	00000000 	nop
  400144:	01001025 	move	v0,t0
  400148:	10000001 	b	400150 <EXIT_f>
  40014c:	00000000 	nop

00400150 <EXIT_f>:
  400150:	8fbf0014 	lw	ra,20(sp)
  400154:	27bd0030 	addiu	sp,sp,48
  400158:	03e00008 	jr	ra
  40015c:	00000000 	nop
