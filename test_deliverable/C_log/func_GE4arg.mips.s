
test_deliverable/C_log/func_GE4arg.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400130 <f6>:
  400130:	27bdffd0 	addiu	sp,sp,-48
  400134:	afbf0018 	sw	ra,24(sp)
  400138:	afa40030 	sw	a0,48(sp)
  40013c:	afa50034 	sw	a1,52(sp)
  400140:	afa60038 	sw	a2,56(sp)
  400144:	afa7003c 	sw	a3,60(sp)
  400148:	8fa40034 	lw	a0,52(sp)
  40014c:	00000000 	nop
  400150:	8fa50038 	lw	a1,56(sp)
  400154:	00000000 	nop
  400158:	8fa6003c 	lw	a2,60(sp)
  40015c:	00000000 	nop
  400160:	8fa70040 	lw	a3,64(sp)
  400164:	00000000 	nop
  400168:	8f998018 	lw	t9,-32744(gp)
  40016c:	04110022 	bal	4001f8 <ff>
  400170:	00000000 	nop
  400174:	00404025 	move	t0,v0
  400178:	afa8002c 	sw	t0,44(sp)
  40017c:	8fa40030 	lw	a0,48(sp)
  400180:	00000000 	nop
  400184:	8fa50034 	lw	a1,52(sp)
  400188:	00000000 	nop
  40018c:	8fa60038 	lw	a2,56(sp)
  400190:	00000000 	nop
  400194:	8fa7003c 	lw	a3,60(sp)
  400198:	00000000 	nop
  40019c:	8fa80040 	lw	t0,64(sp)
  4001a0:	00000000 	nop
  4001a4:	afa80010 	sw	t0,16(sp)
  4001a8:	8fa80044 	lw	t0,68(sp)
  4001ac:	00000000 	nop
  4001b0:	afa80014 	sw	t0,20(sp)
  4001b4:	8f99801c 	lw	t9,-32740(gp)
  4001b8:	0411002a 	bal	400264 <ff2>
  4001bc:	00000000 	nop
  4001c0:	00404025 	move	t0,v0
  4001c4:	8fa9002c 	lw	t1,44(sp)
  4001c8:	00000000 	nop
  4001cc:	01285021 	addu	t2,t1,t0
  4001d0:	afaa0024 	sw	t2,36(sp)
  4001d4:	8fa80024 	lw	t0,36(sp)
  4001d8:	00000000 	nop
  4001dc:	01001025 	move	v0,t0
  4001e0:	10000001 	b	4001e8 <EXIT_f6>
  4001e4:	00000000 	nop

004001e8 <EXIT_f6>:
  4001e8:	8fbf0018 	lw	ra,24(sp)
  4001ec:	27bd0030 	addiu	sp,sp,48
  4001f0:	03e00008 	jr	ra
  4001f4:	00000000 	nop

004001f8 <ff>:
  4001f8:	27bdffd8 	addiu	sp,sp,-40
  4001fc:	afbf0014 	sw	ra,20(sp)
  400200:	afa40028 	sw	a0,40(sp)
  400204:	afa5002c 	sw	a1,44(sp)
  400208:	afa60030 	sw	a2,48(sp)
  40020c:	afa70034 	sw	a3,52(sp)
  400210:	8fa80028 	lw	t0,40(sp)
  400214:	00000000 	nop
  400218:	8fa9002c 	lw	t1,44(sp)
  40021c:	00000000 	nop
  400220:	01095021 	addu	t2,t0,t1
  400224:	8fab0030 	lw	t3,48(sp)
  400228:	00000000 	nop
  40022c:	014b6021 	addu	t4,t2,t3
  400230:	8faa0034 	lw	t2,52(sp)
  400234:	00000000 	nop
  400238:	018a6821 	addu	t5,t4,t2
  40023c:	afad001c 	sw	t5,28(sp)
  400240:	8fa8001c 	lw	t0,28(sp)
  400244:	00000000 	nop
  400248:	01001025 	move	v0,t0
  40024c:	10000001 	b	400254 <EXIT_ff>
  400250:	00000000 	nop

00400254 <EXIT_ff>:
  400254:	8fbf0014 	lw	ra,20(sp)
  400258:	27bd0028 	addiu	sp,sp,40
  40025c:	03e00008 	jr	ra
  400260:	00000000 	nop

00400264 <ff2>:
  400264:	27bdffd0 	addiu	sp,sp,-48
  400268:	afbf0014 	sw	ra,20(sp)
  40026c:	afa40030 	sw	a0,48(sp)
  400270:	afa50034 	sw	a1,52(sp)
  400274:	afa60038 	sw	a2,56(sp)
  400278:	afa7003c 	sw	a3,60(sp)
  40027c:	8fa80030 	lw	t0,48(sp)
  400280:	00000000 	nop
  400284:	8fa90034 	lw	t1,52(sp)
  400288:	00000000 	nop
  40028c:	01095021 	addu	t2,t0,t1
  400290:	8fab0038 	lw	t3,56(sp)
  400294:	00000000 	nop
  400298:	014b6021 	addu	t4,t2,t3
  40029c:	8faa003c 	lw	t2,60(sp)
  4002a0:	00000000 	nop
  4002a4:	018a6821 	addu	t5,t4,t2
  4002a8:	8fac0040 	lw	t4,64(sp)
  4002ac:	00000000 	nop
  4002b0:	01ac7021 	addu	t6,t5,t4
  4002b4:	8fad0044 	lw	t5,68(sp)
  4002b8:	00000000 	nop
  4002bc:	01cd7821 	addu	t7,t6,t5
  4002c0:	afaf001c 	sw	t7,28(sp)
  4002c4:	8fa8001c 	lw	t0,28(sp)
  4002c8:	00000000 	nop
  4002cc:	01001025 	move	v0,t0
  4002d0:	10000001 	b	4002d8 <EXIT_ff2>
  4002d4:	00000000 	nop

004002d8 <EXIT_ff2>:
  4002d8:	8fbf0014 	lw	ra,20(sp)
  4002dc:	27bd0030 	addiu	sp,sp,48
  4002e0:	03e00008 	jr	ra
  4002e4:	00000000 	nop
	...
