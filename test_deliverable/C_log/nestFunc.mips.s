
test_deliverable/C_log/nestFunc.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400130 <f>:
  400130:	27bdffe0 	addiu	sp,sp,-32
  400134:	afbf0014 	sw	ra,20(sp)
  400138:	2408000a 	li	t0,10
  40013c:	afa8001c 	sw	t0,28(sp)
  400140:	8fa8001c 	lw	t0,28(sp)
  400144:	00000000 	nop
  400148:	01001025 	move	v0,t0
  40014c:	10000001 	b	400154 <EXIT_f>
  400150:	00000000 	nop

00400154 <EXIT_f>:
  400154:	8fbf0014 	lw	ra,20(sp)
  400158:	27bd0020 	addiu	sp,sp,32
  40015c:	03e00008 	jr	ra
  400160:	00000000 	nop

00400164 <third>:
  400164:	27bdffd0 	addiu	sp,sp,-48
  400168:	afbf0014 	sw	ra,20(sp)
  40016c:	afa40030 	sw	a0,48(sp)
  400170:	24080014 	li	t0,20
  400174:	8fa90030 	lw	t1,48(sp)
  400178:	00000000 	nop
  40017c:	01285021 	addu	t2,t1,t0
  400180:	2408001e 	li	t0,30
  400184:	01485826 	xor	t3,t2,t0
  400188:	2d6b0001 	sltiu	t3,t3,1
  40018c:	afab0020 	sw	t3,32(sp)
  400190:	8fa80020 	lw	t0,32(sp)
  400194:	00000000 	nop
  400198:	1100000d 	beqz	t0,4001d0 <elseStart_1_third>
  40019c:	00000000 	nop
  4001a0:	8f998018 	lw	t9,-32744(gp)
  4001a4:	0411ffe2 	bal	400130 <f>
  4001a8:	00000000 	nop
  4001ac:	00404025 	move	t0,v0
  4001b0:	afa8001c 	sw	t0,28(sp)
  4001b4:	8fa8001c 	lw	t0,28(sp)
  4001b8:	00000000 	nop
  4001bc:	01001025 	move	v0,t0
  4001c0:	1000000a 	b	4001ec <EXIT_third>
  4001c4:	00000000 	nop
  4001c8:	10000008 	b	4001ec <EXIT_third>
  4001cc:	00000000 	nop

004001d0 <elseStart_1_third>:
  4001d0:	240803e7 	li	t0,999
  4001d4:	afa8001c 	sw	t0,28(sp)
  4001d8:	8fa8001c 	lw	t0,28(sp)
  4001dc:	00000000 	nop
  4001e0:	01001025 	move	v0,t0
  4001e4:	10000001 	b	4001ec <EXIT_third>
  4001e8:	00000000 	nop

004001ec <EXIT_third>:
  4001ec:	8fbf0014 	lw	ra,20(sp)
  4001f0:	27bd0030 	addiu	sp,sp,48
  4001f4:	03e00008 	jr	ra
  4001f8:	00000000 	nop
  4001fc:	00000000 	nop
