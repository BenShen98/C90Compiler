
test_deliverable/C_log/IF_ELSE_F.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <ifelsef>:
  400110:	27bdffd8 	addiu	sp,sp,-40
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	afa40028 	sw	a0,40(sp)
  40011c:	afa5002c 	sw	a1,44(sp)
  400120:	8fa80028 	lw	t0,40(sp)
  400124:	00000000 	nop
  400128:	8fa9002c 	lw	t1,44(sp)
  40012c:	00000000 	nop
  400130:	0109502a 	slt	t2,t0,t1
  400134:	afaa0024 	sw	t2,36(sp)
  400138:	8fa80024 	lw	t0,36(sp)
  40013c:	00000000 	nop
  400140:	1100000a 	beqz	t0,40016c <elseStart_1_ifelsef>
  400144:	00000000 	nop
  400148:	24080002 	li	t0,2
  40014c:	afa80020 	sw	t0,32(sp)
  400150:	8fa80020 	lw	t0,32(sp)
  400154:	00000000 	nop
  400158:	01001025 	move	v0,t0
  40015c:	1000000a 	b	400188 <EXIT_ifelsef>
  400160:	00000000 	nop
  400164:	10000008 	b	400188 <EXIT_ifelsef>
  400168:	00000000 	nop

0040016c <elseStart_1_ifelsef>:
  40016c:	24080000 	li	t0,0
  400170:	afa80020 	sw	t0,32(sp)
  400174:	8fa80020 	lw	t0,32(sp)
  400178:	00000000 	nop
  40017c:	01001025 	move	v0,t0
  400180:	10000001 	b	400188 <EXIT_ifelsef>
  400184:	00000000 	nop

00400188 <EXIT_ifelsef>:
  400188:	8fbf0014 	lw	ra,20(sp)
  40018c:	27bd0028 	addiu	sp,sp,40
  400190:	03e00008 	jr	ra
  400194:	00000000 	nop
	...
