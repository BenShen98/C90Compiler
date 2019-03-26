
test_deliverable/C_log/multRec.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400130 <F>:
  400130:	27bdffc8 	addiu	sp,sp,-56
  400134:	afbf0014 	sw	ra,20(sp)
  400138:	afa40038 	sw	a0,56(sp)
  40013c:	24080000 	li	t0,0
  400140:	8fa90038 	lw	t1,56(sp)
  400144:	00000000 	nop
  400148:	01285026 	xor	t2,t1,t0
  40014c:	2d4a0001 	sltiu	t2,t2,1
  400150:	afaa0030 	sw	t2,48(sp)
  400154:	8fa80030 	lw	t0,48(sp)
  400158:	00000000 	nop
  40015c:	1100000a 	beqz	t0,400188 <elseStart_1_F>
  400160:	00000000 	nop
  400164:	24080001 	li	t0,1
  400168:	afa8002c 	sw	t0,44(sp)
  40016c:	8fa8002c 	lw	t0,44(sp)
  400170:	00000000 	nop
  400174:	01001025 	move	v0,t0
  400178:	1000001e 	b	4001f4 <EXIT_F>
  40017c:	00000000 	nop
  400180:	1000001c 	b	4001f4 <EXIT_F>
  400184:	00000000 	nop

00400188 <elseStart_1_F>:
  400188:	24080001 	li	t0,1
  40018c:	8fa90038 	lw	t1,56(sp)
  400190:	00000000 	nop
  400194:	01285023 	subu	t2,t1,t0
  400198:	afaa0028 	sw	t2,40(sp)
  40019c:	8fa40028 	lw	a0,40(sp)
  4001a0:	00000000 	nop
  4001a4:	8f998018 	lw	t9,-32744(gp)
  4001a8:	0411ffe1 	bal	400130 <F>
  4001ac:	00000000 	nop
  4001b0:	00404025 	move	t0,v0
  4001b4:	afa80024 	sw	t0,36(sp)
  4001b8:	8fa40024 	lw	a0,36(sp)
  4001bc:	00000000 	nop
  4001c0:	8f99801c 	lw	t9,-32740(gp)
  4001c4:	0411000f 	bal	400204 <M>
  4001c8:	00000000 	nop
  4001cc:	00404025 	move	t0,v0
  4001d0:	8fa90038 	lw	t1,56(sp)
  4001d4:	00000000 	nop
  4001d8:	01285023 	subu	t2,t1,t0
  4001dc:	afaa001c 	sw	t2,28(sp)
  4001e0:	8fa8001c 	lw	t0,28(sp)
  4001e4:	00000000 	nop
  4001e8:	01001025 	move	v0,t0
  4001ec:	10000001 	b	4001f4 <EXIT_F>
  4001f0:	00000000 	nop

004001f4 <EXIT_F>:
  4001f4:	8fbf0014 	lw	ra,20(sp)
  4001f8:	27bd0038 	addiu	sp,sp,56
  4001fc:	03e00008 	jr	ra
  400200:	00000000 	nop

00400204 <M>:
  400204:	27bdffc8 	addiu	sp,sp,-56
  400208:	afbf0014 	sw	ra,20(sp)
  40020c:	afa40038 	sw	a0,56(sp)
  400210:	24080000 	li	t0,0
  400214:	8fa90038 	lw	t1,56(sp)
  400218:	00000000 	nop
  40021c:	01285026 	xor	t2,t1,t0
  400220:	2d4a0001 	sltiu	t2,t2,1
  400224:	afaa0030 	sw	t2,48(sp)
  400228:	8fa80030 	lw	t0,48(sp)
  40022c:	00000000 	nop
  400230:	1100000a 	beqz	t0,40025c <elseStart_3_M>
  400234:	00000000 	nop
  400238:	24080000 	li	t0,0
  40023c:	afa8002c 	sw	t0,44(sp)
  400240:	8fa8002c 	lw	t0,44(sp)
  400244:	00000000 	nop
  400248:	01001025 	move	v0,t0
  40024c:	1000001e 	b	4002c8 <EXIT_M>
  400250:	00000000 	nop
  400254:	1000001c 	b	4002c8 <EXIT_M>
  400258:	00000000 	nop

0040025c <elseStart_3_M>:
  40025c:	24080001 	li	t0,1
  400260:	8fa90038 	lw	t1,56(sp)
  400264:	00000000 	nop
  400268:	01285023 	subu	t2,t1,t0
  40026c:	afaa0028 	sw	t2,40(sp)
  400270:	8fa40028 	lw	a0,40(sp)
  400274:	00000000 	nop
  400278:	8f99801c 	lw	t9,-32740(gp)
  40027c:	0411ffe1 	bal	400204 <M>
  400280:	00000000 	nop
  400284:	00404025 	move	t0,v0
  400288:	afa80024 	sw	t0,36(sp)
  40028c:	8fa40024 	lw	a0,36(sp)
  400290:	00000000 	nop
  400294:	8f998018 	lw	t9,-32744(gp)
  400298:	0411ffa5 	bal	400130 <F>
  40029c:	00000000 	nop
  4002a0:	00404025 	move	t0,v0
  4002a4:	8fa90038 	lw	t1,56(sp)
  4002a8:	00000000 	nop
  4002ac:	01285023 	subu	t2,t1,t0
  4002b0:	afaa001c 	sw	t2,28(sp)
  4002b4:	8fa8001c 	lw	t0,28(sp)
  4002b8:	00000000 	nop
  4002bc:	01001025 	move	v0,t0
  4002c0:	10000001 	b	4002c8 <EXIT_M>
  4002c4:	00000000 	nop

004002c8 <EXIT_M>:
  4002c8:	8fbf0014 	lw	ra,20(sp)
  4002cc:	27bd0038 	addiu	sp,sp,56
  4002d0:	03e00008 	jr	ra
  4002d4:	00000000 	nop
	...
