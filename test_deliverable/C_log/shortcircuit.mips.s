
test_deliverable/C_log/shortcircuit.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <f1>:
  400110:	27bdffc8 	addiu	sp,sp,-56
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080000 	li	t0,0
  40011c:	afa80030 	sw	t0,48(sp)
  400120:	8fa80030 	lw	t0,48(sp)
  400124:	00000000 	nop
  400128:	8fa9002c 	lw	t1,44(sp)
  40012c:	00000000 	nop
  400130:	21080001 	addi	t0,t0,1
  400134:	afa80034 	sw	t0,52(sp)
  400138:	8fa80034 	lw	t0,52(sp)
  40013c:	00000000 	nop
  400140:	15000008 	bnez	t0,400164 <ORShort_0_f1>
  400144:	00000000 	nop
  400148:	240a0006 	li	t2,6
  40014c:	15400005 	bnez	t2,400164 <ORShort_0_f1>
  400150:	00000000 	nop
  400154:	00004825 	move	t1,zero
  400158:	afa9002c 	sw	t1,44(sp)
  40015c:	10000003 	b	40016c <OREnd_1_f1>
  400160:	00000000 	nop

00400164 <ORShort_0_f1>:
  400164:	24090001 	li	t1,1
  400168:	afa9002c 	sw	t1,44(sp)

0040016c <OREnd_1_f1>:
  40016c:	240b0002 	li	t3,2
  400170:	01696004 	sllv	t4,t1,t3
  400174:	01885821 	addu	t3,t4,t0
  400178:	afaa0028 	sw	t2,40(sp)
  40017c:	afab001c 	sw	t3,28(sp)
  400180:	8fa8001c 	lw	t0,28(sp)
  400184:	00000000 	nop
  400188:	01001025 	move	v0,t0
  40018c:	10000001 	b	400194 <EXIT_f1>
  400190:	00000000 	nop

00400194 <EXIT_f1>:
  400194:	8fbf0014 	lw	ra,20(sp)
  400198:	27bd0038 	addiu	sp,sp,56
  40019c:	03e00008 	jr	ra
  4001a0:	00000000 	nop

004001a4 <f2>:
  4001a4:	27bdffc8 	addiu	sp,sp,-56
  4001a8:	afbf0014 	sw	ra,20(sp)
  4001ac:	24080000 	li	t0,0
  4001b0:	afa80030 	sw	t0,48(sp)
  4001b4:	8fa80030 	lw	t0,48(sp)
  4001b8:	00000000 	nop
  4001bc:	8fa9002c 	lw	t1,44(sp)
  4001c0:	00000000 	nop
  4001c4:	240a0006 	li	t2,6
  4001c8:	1540000b 	bnez	t2,4001f8 <ORShort_2_f2>
  4001cc:	00000000 	nop
  4001d0:	21080001 	addi	t0,t0,1
  4001d4:	afa80034 	sw	t0,52(sp)
  4001d8:	8fa80034 	lw	t0,52(sp)
  4001dc:	00000000 	nop
  4001e0:	15000005 	bnez	t0,4001f8 <ORShort_2_f2>
  4001e4:	00000000 	nop
  4001e8:	00004825 	move	t1,zero
  4001ec:	afa9002c 	sw	t1,44(sp)
  4001f0:	10000003 	b	400200 <OREnd_3_f2>
  4001f4:	00000000 	nop

004001f8 <ORShort_2_f2>:
  4001f8:	24090001 	li	t1,1
  4001fc:	afa9002c 	sw	t1,44(sp)

00400200 <OREnd_3_f2>:
  400200:	240b0002 	li	t3,2
  400204:	01696004 	sllv	t4,t1,t3
  400208:	01885821 	addu	t3,t4,t0
  40020c:	afaa0028 	sw	t2,40(sp)
  400210:	afab001c 	sw	t3,28(sp)
  400214:	8fa8001c 	lw	t0,28(sp)
  400218:	00000000 	nop
  40021c:	01001025 	move	v0,t0
  400220:	10000001 	b	400228 <EXIT_f2>
  400224:	00000000 	nop

00400228 <EXIT_f2>:
  400228:	8fbf0014 	lw	ra,20(sp)
  40022c:	27bd0038 	addiu	sp,sp,56
  400230:	03e00008 	jr	ra
  400234:	00000000 	nop

00400238 <f3>:
  400238:	27bdffc8 	addiu	sp,sp,-56
  40023c:	afbf0014 	sw	ra,20(sp)
  400240:	24080001 	li	t0,1
  400244:	afa80030 	sw	t0,48(sp)
  400248:	8fa80030 	lw	t0,48(sp)
  40024c:	00000000 	nop
  400250:	21080001 	addi	t0,t0,1
  400254:	afa80034 	sw	t0,52(sp)
  400258:	8fa80034 	lw	t0,52(sp)
  40025c:	00000000 	nop
  400260:	11000008 	beqz	t0,400284 <ANDShort_4_f3>
  400264:	00000000 	nop
  400268:	240a0000 	li	t2,0
  40026c:	11400005 	beqz	t2,400284 <ANDShort_4_f3>
  400270:	00000000 	nop
  400274:	24090001 	li	t1,1
  400278:	afa9002c 	sw	t1,44(sp)
  40027c:	10000003 	b	40028c <ANDEnd_5_f3>
  400280:	00000000 	nop

00400284 <ANDShort_4_f3>:
  400284:	00004825 	move	t1,zero
  400288:	afa9002c 	sw	t1,44(sp)

0040028c <ANDEnd_5_f3>:
  40028c:	240b0002 	li	t3,2
  400290:	01696004 	sllv	t4,t1,t3
  400294:	01885821 	addu	t3,t4,t0
  400298:	afaa0028 	sw	t2,40(sp)
  40029c:	afab001c 	sw	t3,28(sp)
  4002a0:	8fa8001c 	lw	t0,28(sp)
  4002a4:	00000000 	nop
  4002a8:	01001025 	move	v0,t0
  4002ac:	10000001 	b	4002b4 <EXIT_f3>
  4002b0:	00000000 	nop

004002b4 <EXIT_f3>:
  4002b4:	8fbf0014 	lw	ra,20(sp)
  4002b8:	27bd0038 	addiu	sp,sp,56
  4002bc:	03e00008 	jr	ra
  4002c0:	00000000 	nop

004002c4 <f4>:
  4002c4:	27bdffc8 	addiu	sp,sp,-56
  4002c8:	afbf0014 	sw	ra,20(sp)
  4002cc:	24080001 	li	t0,1
  4002d0:	afa80030 	sw	t0,48(sp)
  4002d4:	8fa80030 	lw	t0,48(sp)
  4002d8:	00000000 	nop
  4002dc:	240a0000 	li	t2,0
  4002e0:	1140000b 	beqz	t2,400310 <ANDShort_6_f4>
  4002e4:	00000000 	nop
  4002e8:	21080001 	addi	t0,t0,1
  4002ec:	afa80034 	sw	t0,52(sp)
  4002f0:	8fa80034 	lw	t0,52(sp)
  4002f4:	00000000 	nop
  4002f8:	11000005 	beqz	t0,400310 <ANDShort_6_f4>
  4002fc:	00000000 	nop
  400300:	24090001 	li	t1,1
  400304:	afa9002c 	sw	t1,44(sp)
  400308:	10000003 	b	400318 <ANDEnd_7_f4>
  40030c:	00000000 	nop

00400310 <ANDShort_6_f4>:
  400310:	00004825 	move	t1,zero
  400314:	afa9002c 	sw	t1,44(sp)

00400318 <ANDEnd_7_f4>:
  400318:	240b0002 	li	t3,2
  40031c:	01696004 	sllv	t4,t1,t3
  400320:	01885821 	addu	t3,t4,t0
  400324:	afaa0028 	sw	t2,40(sp)
  400328:	afab001c 	sw	t3,28(sp)
  40032c:	8fa8001c 	lw	t0,28(sp)
  400330:	00000000 	nop
  400334:	01001025 	move	v0,t0
  400338:	10000001 	b	400340 <EXIT_f4>
  40033c:	00000000 	nop

00400340 <EXIT_f4>:
  400340:	8fbf0014 	lw	ra,20(sp)
  400344:	27bd0038 	addiu	sp,sp,56
  400348:	03e00008 	jr	ra
  40034c:	00000000 	nop
