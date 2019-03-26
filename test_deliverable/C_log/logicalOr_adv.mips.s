
test_deliverable/C_log/logicalOr_adv.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <f>:
  400110:	27bdff60 	addiu	sp,sp,-160
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080000 	li	t0,0
  40011c:	8fa90098 	lw	t1,152(sp)
  400120:	00000000 	nop
  400124:	8faa0094 	lw	t2,148(sp)
  400128:	00000000 	nop
  40012c:	8fab0090 	lw	t3,144(sp)
  400130:	00000000 	nop
  400134:	8fac008c 	lw	t4,140(sp)
  400138:	00000000 	nop
  40013c:	8fad0088 	lw	t5,136(sp)
  400140:	00000000 	nop
  400144:	8fae0084 	lw	t6,132(sp)
  400148:	00000000 	nop
  40014c:	8faf0080 	lw	t7,128(sp)
  400150:	00000000 	nop
  400154:	afa8009c 	sw	t0,156(sp)
  400158:	8fa8007c 	lw	t0,124(sp)
  40015c:	00000000 	nop
  400160:	8fa90078 	lw	t1,120(sp)
  400164:	00000000 	nop
  400168:	8faa009c 	lw	t2,156(sp)
  40016c:	00000000 	nop
  400170:	214a0001 	addi	t2,t2,1
  400174:	afaa009c 	sw	t2,156(sp)
  400178:	240a0003 	li	t2,3
  40017c:	8fab009c 	lw	t3,156(sp)
  400180:	00000000 	nop
  400184:	014b602a 	slt	t4,t2,t3
  400188:	1580000d 	bnez	t4,4001c0 <ORShort_17_f>
  40018c:	00000000 	nop
  400190:	216b0001 	addi	t3,t3,1
  400194:	afab009c 	sw	t3,156(sp)
  400198:	240a0003 	li	t2,3
  40019c:	8fab009c 	lw	t3,156(sp)
  4001a0:	00000000 	nop
  4001a4:	014b682a 	slt	t5,t2,t3
  4001a8:	15a00005 	bnez	t5,4001c0 <ORShort_17_f>
  4001ac:	00000000 	nop
  4001b0:	00004825 	move	t1,zero
  4001b4:	afa90078 	sw	t1,120(sp)
  4001b8:	10000003 	b	4001c8 <OREnd_18_f>
  4001bc:	00000000 	nop

004001c0 <ORShort_17_f>:
  4001c0:	24090001 	li	t1,1
  4001c4:	afa90078 	sw	t1,120(sp)

004001c8 <OREnd_18_f>:
  4001c8:	1520000d 	bnez	t1,400200 <ORShort_15_f>
  4001cc:	00000000 	nop
  4001d0:	216b0001 	addi	t3,t3,1
  4001d4:	afab009c 	sw	t3,156(sp)
  4001d8:	240a0003 	li	t2,3
  4001dc:	8fab009c 	lw	t3,156(sp)
  4001e0:	00000000 	nop
  4001e4:	014b702a 	slt	t6,t2,t3
  4001e8:	15c00005 	bnez	t6,400200 <ORShort_15_f>
  4001ec:	00000000 	nop
  4001f0:	00004025 	move	t0,zero
  4001f4:	afa8007c 	sw	t0,124(sp)
  4001f8:	10000003 	b	400208 <OREnd_16_f>
  4001fc:	00000000 	nop

00400200 <ORShort_15_f>:
  400200:	24080001 	li	t0,1
  400204:	afa8007c 	sw	t0,124(sp)

00400208 <OREnd_16_f>:
  400208:	1500000f 	bnez	t0,400248 <ORShort_13_f>
  40020c:	00000000 	nop
  400210:	216b0001 	addi	t3,t3,1
  400214:	afab009c 	sw	t3,156(sp)
  400218:	240a0003 	li	t2,3
  40021c:	8fab009c 	lw	t3,156(sp)
  400220:	00000000 	nop
  400224:	014b782a 	slt	t7,t2,t3
  400228:	15e00007 	bnez	t7,400248 <ORShort_13_f>
  40022c:	00000000 	nop
  400230:	8faa0080 	lw	t2,128(sp)
  400234:	00000000 	nop
  400238:	00005025 	move	t2,zero
  40023c:	afaa0080 	sw	t2,128(sp)
  400240:	10000003 	b	400250 <OREnd_14_f>
  400244:	00000000 	nop

00400248 <ORShort_13_f>:
  400248:	240a0001 	li	t2,1
  40024c:	afaa0080 	sw	t2,128(sp)

00400250 <OREnd_14_f>:
  400250:	1540000f 	bnez	t2,400290 <ORShort_11_f>
  400254:	00000000 	nop
  400258:	216b0001 	addi	t3,t3,1
  40025c:	afab009c 	sw	t3,156(sp)
  400260:	240b0003 	li	t3,3
  400264:	8fa8009c 	lw	t0,156(sp)
  400268:	00000000 	nop
  40026c:	0168482a 	slt	t1,t3,t0
  400270:	15200007 	bnez	t1,400290 <ORShort_11_f>
  400274:	00000000 	nop
  400278:	8fab0084 	lw	t3,132(sp)
  40027c:	00000000 	nop
  400280:	00005825 	move	t3,zero
  400284:	afab0084 	sw	t3,132(sp)
  400288:	10000003 	b	400298 <OREnd_12_f>
  40028c:	00000000 	nop

00400290 <ORShort_11_f>:
  400290:	240b0001 	li	t3,1
  400294:	afab0084 	sw	t3,132(sp)

00400298 <OREnd_12_f>:
  400298:	15600011 	bnez	t3,4002e0 <ORShort_9_f>
  40029c:	00000000 	nop
  4002a0:	21080001 	addi	t0,t0,1
  4002a4:	afa8009c 	sw	t0,156(sp)
  4002a8:	24080003 	li	t0,3
  4002ac:	afac0070 	sw	t4,112(sp)
  4002b0:	8fac009c 	lw	t4,156(sp)
  4002b4:	00000000 	nop
  4002b8:	afad0068 	sw	t5,104(sp)
  4002bc:	010c682a 	slt	t5,t0,t4
  4002c0:	15a00007 	bnez	t5,4002e0 <ORShort_9_f>
  4002c4:	00000000 	nop
  4002c8:	8fa80088 	lw	t0,136(sp)
  4002cc:	00000000 	nop
  4002d0:	00004025 	move	t0,zero
  4002d4:	afa80088 	sw	t0,136(sp)
  4002d8:	10000003 	b	4002e8 <OREnd_10_f>
  4002dc:	00000000 	nop

004002e0 <ORShort_9_f>:
  4002e0:	24080001 	li	t0,1
  4002e4:	afa80088 	sw	t0,136(sp)

004002e8 <OREnd_10_f>:
  4002e8:	15000011 	bnez	t0,400330 <ORShort_7_f>
  4002ec:	00000000 	nop
  4002f0:	218c0001 	addi	t4,t4,1
  4002f4:	afac009c 	sw	t4,156(sp)
  4002f8:	240c0003 	li	t4,3
  4002fc:	afae0060 	sw	t6,96(sp)
  400300:	8fae009c 	lw	t6,156(sp)
  400304:	00000000 	nop
  400308:	afaf0058 	sw	t7,88(sp)
  40030c:	018e782a 	slt	t7,t4,t6
  400310:	15e00007 	bnez	t7,400330 <ORShort_7_f>
  400314:	00000000 	nop
  400318:	8fac008c 	lw	t4,140(sp)
  40031c:	00000000 	nop
  400320:	00006025 	move	t4,zero
  400324:	afac008c 	sw	t4,140(sp)
  400328:	10000003 	b	400338 <OREnd_8_f>
  40032c:	00000000 	nop

00400330 <ORShort_7_f>:
  400330:	240c0001 	li	t4,1
  400334:	afac008c 	sw	t4,140(sp)

00400338 <OREnd_8_f>:
  400338:	15800010 	bnez	t4,40037c <ORShort_5_f>
  40033c:	00000000 	nop
  400340:	21ce0001 	addi	t6,t6,1
  400344:	afae009c 	sw	t6,156(sp)
  400348:	240e0003 	li	t6,3
  40034c:	8faa009c 	lw	t2,156(sp)
  400350:	00000000 	nop
  400354:	afa90050 	sw	t1,80(sp)
  400358:	01ca482a 	slt	t1,t6,t2
  40035c:	15200007 	bnez	t1,40037c <ORShort_5_f>
  400360:	00000000 	nop
  400364:	8fae0090 	lw	t6,144(sp)
  400368:	00000000 	nop
  40036c:	00007025 	move	t6,zero
  400370:	afae0090 	sw	t6,144(sp)
  400374:	10000003 	b	400384 <OREnd_6_f>
  400378:	00000000 	nop

0040037c <ORShort_5_f>:
  40037c:	240e0001 	li	t6,1
  400380:	afae0090 	sw	t6,144(sp)

00400384 <OREnd_6_f>:
  400384:	15c00010 	bnez	t6,4003c8 <ORShort_3_f>
  400388:	00000000 	nop
  40038c:	214a0001 	addi	t2,t2,1
  400390:	afaa009c 	sw	t2,156(sp)
  400394:	240a0003 	li	t2,3
  400398:	8fab009c 	lw	t3,156(sp)
  40039c:	00000000 	nop
  4003a0:	afad0048 	sw	t5,72(sp)
  4003a4:	014b682a 	slt	t5,t2,t3
  4003a8:	15a00007 	bnez	t5,4003c8 <ORShort_3_f>
  4003ac:	00000000 	nop
  4003b0:	8faa0094 	lw	t2,148(sp)
  4003b4:	00000000 	nop
  4003b8:	00005025 	move	t2,zero
  4003bc:	afaa0094 	sw	t2,148(sp)
  4003c0:	10000003 	b	4003d0 <OREnd_4_f>
  4003c4:	00000000 	nop

004003c8 <ORShort_3_f>:
  4003c8:	240a0001 	li	t2,1
  4003cc:	afaa0094 	sw	t2,148(sp)

004003d0 <OREnd_4_f>:
  4003d0:	15400010 	bnez	t2,400414 <ORShort_1_f>
  4003d4:	00000000 	nop
  4003d8:	216b0001 	addi	t3,t3,1
  4003dc:	afab009c 	sw	t3,156(sp)
  4003e0:	240b0003 	li	t3,3
  4003e4:	8fa8009c 	lw	t0,156(sp)
  4003e8:	00000000 	nop
  4003ec:	afaf0040 	sw	t7,64(sp)
  4003f0:	0168782a 	slt	t7,t3,t0
  4003f4:	15e00007 	bnez	t7,400414 <ORShort_1_f>
  4003f8:	00000000 	nop
  4003fc:	8fab0098 	lw	t3,152(sp)
  400400:	00000000 	nop
  400404:	00005825 	move	t3,zero
  400408:	afab0098 	sw	t3,152(sp)
  40040c:	10000003 	b	40041c <OREnd_2_f>
  400410:	00000000 	nop

00400414 <ORShort_1_f>:
  400414:	240b0001 	li	t3,1
  400418:	afab0098 	sw	t3,152(sp)

0040041c <OREnd_2_f>:
  40041c:	afa90038 	sw	t1,56(sp)
  400420:	afad0030 	sw	t5,48(sp)
  400424:	afaf0028 	sw	t7,40(sp)
  400428:	8fa80098 	lw	t0,152(sp)
  40042c:	00000000 	nop
  400430:	11000009 	beqz	t0,400458 <elseStart_19_f>
  400434:	00000000 	nop
  400438:	8fa8009c 	lw	t0,156(sp)
  40043c:	00000000 	nop
  400440:	01001025 	move	v0,t0
  400444:	1000000c 	b	400478 <EXIT_f>
  400448:	00000000 	nop
  40044c:	afa80024 	sw	t0,36(sp)
  400450:	10000008 	b	400474 <ifEnd_0_f>
  400454:	00000000 	nop

00400458 <elseStart_19_f>:
  400458:	24080058 	li	t0,88
  40045c:	afa80020 	sw	t0,32(sp)
  400460:	8fa80020 	lw	t0,32(sp)
  400464:	00000000 	nop
  400468:	01001025 	move	v0,t0
  40046c:	10000002 	b	400478 <EXIT_f>
  400470:	00000000 	nop

00400474 <ifEnd_0_f>:
  400474:	afa8001c 	sw	t0,28(sp)

00400478 <EXIT_f>:
  400478:	8fbf0014 	lw	ra,20(sp)
  40047c:	27bd00a0 	addiu	sp,sp,160
  400480:	03e00008 	jr	ra
  400484:	00000000 	nop
	...
