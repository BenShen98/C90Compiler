
test_deliverable/C_log/LOCAL_ARRAY.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <f>:
  400110:	27bdff78 	addiu	sp,sp,-136
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	afa40088 	sw	a0,136(sp)
  40011c:	afa5008c 	sw	a1,140(sp)
  400120:	24080000 	li	t0,0
  400124:	afa80070 	sw	t0,112(sp)
  400128:	8fa80070 	lw	t0,112(sp)
  40012c:	00000000 	nop
  400130:	24090005 	li	t1,5
  400134:	afa80074 	sw	t0,116(sp)
  400138:	afa9006c 	sw	t1,108(sp)
  40013c:	8fa8006c 	lw	t0,108(sp)
  400140:	00000000 	nop
  400144:	24090002 	li	t1,2
  400148:	afa80078 	sw	t0,120(sp)
  40014c:	afa90068 	sw	t1,104(sp)
  400150:	8fa80068 	lw	t0,104(sp)
  400154:	00000000 	nop
  400158:	24090003 	li	t1,3
  40015c:	afa8007c 	sw	t0,124(sp)
  400160:	afa90064 	sw	t1,100(sp)
  400164:	8fa80064 	lw	t0,100(sp)
  400168:	00000000 	nop
  40016c:	24090000 	li	t1,0
  400170:	afa80080 	sw	t0,128(sp)
  400174:	afa90060 	sw	t1,96(sp)
  400178:	8fa80060 	lw	t0,96(sp)
  40017c:	00000000 	nop
  400180:	24090000 	li	t1,0
  400184:	240a0000 	li	t2,0
  400188:	8fab0054 	lw	t3,84(sp)
  40018c:	00000000 	nop
  400190:	27ab0074 	addiu	t3,sp,116
  400194:	8fac008c 	lw	t4,140(sp)
  400198:	00000000 	nop
  40019c:	240d0004 	li	t5,4
  4001a0:	018d0018 	mult	t4,t5
  4001a4:	00007012 	mflo	t6
  4001a8:	016e7821 	addu	t7,t3,t6
  4001ac:	afa80084 	sw	t0,132(sp)
  4001b0:	afa9005c 	sw	t1,92(sp)
  4001b4:	afaa0058 	sw	t2,88(sp)
  4001b8:	afab0054 	sw	t3,84(sp)
  4001bc:	afad0050 	sw	t5,80(sp)
  4001c0:	afaf0048 	sw	t7,72(sp)
  4001c4:	8fa80048 	lw	t0,72(sp)
  4001c8:	00000000 	nop
  4001cc:	8fa9008c 	lw	t1,140(sp)
  4001d0:	00000000 	nop
  4001d4:	ad090000 	sw	t1,0(t0)
  4001d8:	8faa0044 	lw	t2,68(sp)
  4001dc:	00000000 	nop
  4001e0:	27aa0074 	addiu	t2,sp,116
  4001e4:	8fab0088 	lw	t3,136(sp)
  4001e8:	00000000 	nop
  4001ec:	240c0004 	li	t4,4
  4001f0:	016c0018 	mult	t3,t4
  4001f4:	00006812 	mflo	t5
  4001f8:	014d7021 	addu	t6,t2,t5
  4001fc:	afaa0044 	sw	t2,68(sp)
  400200:	afac0040 	sw	t4,64(sp)
  400204:	afae0038 	sw	t6,56(sp)
  400208:	8fa80038 	lw	t0,56(sp)
  40020c:	00000000 	nop
  400210:	8d080000 	lw	t0,0(t0)
  400214:	00000000 	nop
  400218:	8fa90030 	lw	t1,48(sp)
  40021c:	00000000 	nop
  400220:	27a90074 	addiu	t1,sp,116
  400224:	8faa008c 	lw	t2,140(sp)
  400228:	00000000 	nop
  40022c:	240b0004 	li	t3,4
  400230:	014b0018 	mult	t2,t3
  400234:	00006012 	mflo	t4
  400238:	012c6821 	addu	t5,t1,t4
  40023c:	afa8005c 	sw	t0,92(sp)
  400240:	afa90030 	sw	t1,48(sp)
  400244:	afab002c 	sw	t3,44(sp)
  400248:	afad0024 	sw	t5,36(sp)
  40024c:	8fa80024 	lw	t0,36(sp)
  400250:	00000000 	nop
  400254:	8d080000 	lw	t0,0(t0)
  400258:	00000000 	nop
  40025c:	8fa9005c 	lw	t1,92(sp)
  400260:	00000000 	nop
  400264:	01285021 	addu	t2,t1,t0
  400268:	afa80058 	sw	t0,88(sp)
  40026c:	afaa001c 	sw	t2,28(sp)
  400270:	8fa8001c 	lw	t0,28(sp)
  400274:	00000000 	nop
  400278:	01001025 	move	v0,t0
  40027c:	10000001 	b	400284 <EXIT_f>
  400280:	00000000 	nop

00400284 <EXIT_f>:
  400284:	8fbf0014 	lw	ra,20(sp)
  400288:	27bd0088 	addiu	sp,sp,136
  40028c:	03e00008 	jr	ra
  400290:	00000000 	nop
	...
