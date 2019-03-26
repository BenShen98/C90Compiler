
test_deliverable/C_log/ifelse.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <testifelse>:
  400110:	27bdffd0 	addiu	sp,sp,-48
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080001 	li	t0,1
  40011c:	afa8002c 	sw	t0,44(sp)
  400120:	8fa8002c 	lw	t0,44(sp)
  400124:	00000000 	nop
  400128:	11000019 	beqz	t0,400190 <elseStart_1_testifelse>
  40012c:	00000000 	nop
  400130:	24080001 	li	t0,1
  400134:	afa80028 	sw	t0,40(sp)
  400138:	8fa80028 	lw	t0,40(sp)
  40013c:	00000000 	nop
  400140:	1100000a 	beqz	t0,40016c <elseStart_3_testifelse>
  400144:	00000000 	nop
  400148:	24080001 	li	t0,1
  40014c:	afa80020 	sw	t0,32(sp)
  400150:	8fa80020 	lw	t0,32(sp)
  400154:	00000000 	nop
  400158:	01001025 	move	v0,t0
  40015c:	10000013 	b	4001ac <EXIT_testifelse>
  400160:	00000000 	nop
  400164:	10000008 	b	400188 <ifEnd_2_testifelse>
  400168:	00000000 	nop

0040016c <elseStart_3_testifelse>:
  40016c:	24080002 	li	t0,2
  400170:	afa80020 	sw	t0,32(sp)
  400174:	8fa80020 	lw	t0,32(sp)
  400178:	00000000 	nop
  40017c:	01001025 	move	v0,t0
  400180:	1000000a 	b	4001ac <EXIT_testifelse>
  400184:	00000000 	nop

00400188 <ifEnd_2_testifelse>:
  400188:	10000008 	b	4001ac <EXIT_testifelse>
  40018c:	00000000 	nop

00400190 <elseStart_1_testifelse>:
  400190:	24080003 	li	t0,3
  400194:	afa80028 	sw	t0,40(sp)
  400198:	8fa80028 	lw	t0,40(sp)
  40019c:	00000000 	nop
  4001a0:	01001025 	move	v0,t0
  4001a4:	10000001 	b	4001ac <EXIT_testifelse>
  4001a8:	00000000 	nop

004001ac <EXIT_testifelse>:
  4001ac:	8fbf0014 	lw	ra,20(sp)
  4001b0:	27bd0030 	addiu	sp,sp,48
  4001b4:	03e00008 	jr	ra
  4001b8:	00000000 	nop
  4001bc:	00000000 	nop
