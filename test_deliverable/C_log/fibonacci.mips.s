
test_deliverable/C_log/fibonacci.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400130 <Fibonacci>:
  400130:	27bdffb8 	addiu	sp,sp,-72
  400134:	afbf0014 	sw	ra,20(sp)
  400138:	afa40048 	sw	a0,72(sp)
  40013c:	24080000 	li	t0,0
  400140:	8fa90048 	lw	t1,72(sp)
  400144:	00000000 	nop
  400148:	01285026 	xor	t2,t1,t0
  40014c:	2d4a0001 	sltiu	t2,t2,1
  400150:	afaa0040 	sw	t2,64(sp)
  400154:	8fa80040 	lw	t0,64(sp)
  400158:	00000000 	nop
  40015c:	1100000a 	beqz	t0,400188 <elseStart_1_Fibonacci>
  400160:	00000000 	nop
  400164:	24080000 	li	t0,0
  400168:	afa80034 	sw	t0,52(sp)
  40016c:	8fa80034 	lw	t0,52(sp)
  400170:	00000000 	nop
  400174:	01001025 	move	v0,t0
  400178:	10000036 	b	400254 <EXIT_Fibonacci>
  40017c:	00000000 	nop
  400180:	10000034 	b	400254 <EXIT_Fibonacci>
  400184:	00000000 	nop

00400188 <elseStart_1_Fibonacci>:
  400188:	24080001 	li	t0,1
  40018c:	8fa90048 	lw	t1,72(sp)
  400190:	00000000 	nop
  400194:	01285026 	xor	t2,t1,t0
  400198:	2d4a0001 	sltiu	t2,t2,1
  40019c:	afaa0038 	sw	t2,56(sp)
  4001a0:	8fa80038 	lw	t0,56(sp)
  4001a4:	00000000 	nop
  4001a8:	1100000a 	beqz	t0,4001d4 <elseStart_3_Fibonacci>
  4001ac:	00000000 	nop
  4001b0:	24080001 	li	t0,1
  4001b4:	afa80034 	sw	t0,52(sp)
  4001b8:	8fa80034 	lw	t0,52(sp)
  4001bc:	00000000 	nop
  4001c0:	01001025 	move	v0,t0
  4001c4:	10000023 	b	400254 <EXIT_Fibonacci>
  4001c8:	00000000 	nop
  4001cc:	10000021 	b	400254 <EXIT_Fibonacci>
  4001d0:	00000000 	nop

004001d4 <elseStart_3_Fibonacci>:
  4001d4:	24080001 	li	t0,1
  4001d8:	8fa90048 	lw	t1,72(sp)
  4001dc:	00000000 	nop
  4001e0:	01285023 	subu	t2,t1,t0
  4001e4:	afaa0030 	sw	t2,48(sp)
  4001e8:	8fa40030 	lw	a0,48(sp)
  4001ec:	00000000 	nop
  4001f0:	8f998018 	lw	t9,-32744(gp)
  4001f4:	0411ffce 	bal	400130 <Fibonacci>
  4001f8:	00000000 	nop
  4001fc:	00404025 	move	t0,v0
  400200:	24090002 	li	t1,2
  400204:	8faa0048 	lw	t2,72(sp)
  400208:	00000000 	nop
  40020c:	01495823 	subu	t3,t2,t1
  400210:	afa8002c 	sw	t0,44(sp)
  400214:	afab0024 	sw	t3,36(sp)
  400218:	8fa40024 	lw	a0,36(sp)
  40021c:	00000000 	nop
  400220:	8f998018 	lw	t9,-32744(gp)
  400224:	0411ffc2 	bal	400130 <Fibonacci>
  400228:	00000000 	nop
  40022c:	00404025 	move	t0,v0
  400230:	8fa9002c 	lw	t1,44(sp)
  400234:	00000000 	nop
  400238:	01285021 	addu	t2,t1,t0
  40023c:	afaa001c 	sw	t2,28(sp)
  400240:	8fa8001c 	lw	t0,28(sp)
  400244:	00000000 	nop
  400248:	01001025 	move	v0,t0
  40024c:	10000001 	b	400254 <EXIT_Fibonacci>
  400250:	00000000 	nop

00400254 <EXIT_Fibonacci>:
  400254:	8fbf0014 	lw	ra,20(sp)
  400258:	27bd0048 	addiu	sp,sp,72
  40025c:	03e00008 	jr	ra
  400260:	00000000 	nop
	...
