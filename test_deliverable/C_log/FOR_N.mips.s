
test_deliverable/C_log/FOR_N.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <testfor>:
  400110:	27bdffa8 	addiu	sp,sp,-88
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080000 	li	t0,0
  40011c:	afa80050 	sw	t0,80(sp)
  400120:	8fa80050 	lw	t0,80(sp)
  400124:	00000000 	nop
  400128:	24090000 	li	t1,0
  40012c:	240a0005 	li	t2,5
  400130:	afa80054 	sw	t0,84(sp)
  400134:	afa9004c 	sw	t1,76(sp)
  400138:	afaa0044 	sw	t2,68(sp)
  40013c:	8fa80044 	lw	t0,68(sp)
  400140:	00000000 	nop
  400144:	24090000 	li	t1,0
  400148:	afa80048 	sw	t0,72(sp)
  40014c:	afa90040 	sw	t1,64(sp)
  400150:	8fa80040 	lw	t0,64(sp)
  400154:	00000000 	nop
  400158:	afa8004c 	sw	t0,76(sp)

0040015c <ItrCondition_0_testfor>:
  40015c:	24080000 	li	t0,0
  400160:	1100000c 	beqz	t0,400194 <ItrEnd_1_testfor>
  400164:	00000000 	nop
  400168:	afa8003c 	sw	t0,60(sp)
  40016c:	24080001 	li	t0,1
  400170:	afa80020 	sw	t0,32(sp)
  400174:	8fa80054 	lw	t0,84(sp)
  400178:	00000000 	nop
  40017c:	8fa90020 	lw	t1,32(sp)
  400180:	00000000 	nop
  400184:	01095021 	addu	t2,t0,t1

00400188 <conti_2_testfor>:
  400188:	afaa0054 	sw	t2,84(sp)
  40018c:	1000fff3 	b	40015c <ItrCondition_0_testfor>
  400190:	00000000 	nop

00400194 <ItrEnd_1_testfor>:
  400194:	24080000 	li	t0,0
  400198:	afa80038 	sw	t0,56(sp)
  40019c:	8fa80038 	lw	t0,56(sp)
  4001a0:	00000000 	nop
  4001a4:	afa8004c 	sw	t0,76(sp)

004001a8 <ItrCondition_3_testfor>:
  4001a8:	8fa80048 	lw	t0,72(sp)
  4001ac:	00000000 	nop
  4001b0:	11000008 	beqz	t0,4001d4 <ItrEnd_4_testfor>
  4001b4:	00000000 	nop

004001b8 <conti_5_testfor>:
  4001b8:	8fa80048 	lw	t0,72(sp)
  4001bc:	00000000 	nop
  4001c0:	2109ffff 	addi	t1,t0,-1
  4001c4:	afa80034 	sw	t0,52(sp)
  4001c8:	afa90048 	sw	t1,72(sp)
  4001cc:	1000fff6 	b	4001a8 <ItrCondition_3_testfor>
  4001d0:	00000000 	nop

004001d4 <ItrEnd_4_testfor>:
  4001d4:	8fa80054 	lw	t0,84(sp)
  4001d8:	00000000 	nop
  4001dc:	8fa90048 	lw	t1,72(sp)
  4001e0:	00000000 	nop
  4001e4:	01095021 	addu	t2,t0,t1
  4001e8:	240b0006 	li	t3,6
  4001ec:	014b6021 	addu	t4,t2,t3
  4001f0:	afac0028 	sw	t4,40(sp)
  4001f4:	8fa80028 	lw	t0,40(sp)
  4001f8:	00000000 	nop
  4001fc:	01001025 	move	v0,t0
  400200:	10000001 	b	400208 <EXIT_testfor>
  400204:	00000000 	nop

00400208 <EXIT_testfor>:
  400208:	8fbf0014 	lw	ra,20(sp)
  40020c:	27bd0058 	addiu	sp,sp,88
  400210:	03e00008 	jr	ra
  400214:	00000000 	nop
	...
