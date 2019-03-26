
test_deliverable/C_log/oneLif.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <oneLif>:
  400110:	27bdffa8 	addiu	sp,sp,-88
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080005 	li	t0,5
  40011c:	afa80050 	sw	t0,80(sp)
  400120:	8fa80050 	lw	t0,80(sp)
  400124:	00000000 	nop
  400128:	24090004 	li	t1,4
  40012c:	01095026 	xor	t2,t0,t1
  400130:	2d4a0001 	sltiu	t2,t2,1
  400134:	afa80054 	sw	t0,84(sp)
  400138:	afaa0040 	sw	t2,64(sp)
  40013c:	8fa80040 	lw	t0,64(sp)
  400140:	00000000 	nop
  400144:	11000008 	beqz	t0,400168 <elseStart_0_oneLif>
  400148:	00000000 	nop
  40014c:	2409004d 	li	t1,77
  400150:	afa9003c 	sw	t1,60(sp)
  400154:	8fa8003c 	lw	t0,60(sp)
  400158:	00000000 	nop
  40015c:	afa80048 	sw	t0,72(sp)
  400160:	10000006 	b	40017c <elseEnd_1_oneLif>
  400164:	00000000 	nop

00400168 <elseStart_0_oneLif>:
  400168:	24080002 	li	t0,2
  40016c:	afa80038 	sw	t0,56(sp)
  400170:	8fa80038 	lw	t0,56(sp)
  400174:	00000000 	nop
  400178:	afa80048 	sw	t0,72(sp)

0040017c <elseEnd_1_oneLif>:
  40017c:	8fa80048 	lw	t0,72(sp)
  400180:	00000000 	nop
  400184:	24090005 	li	t1,5
  400188:	8faa0054 	lw	t2,84(sp)
  40018c:	00000000 	nop
  400190:	01495826 	xor	t3,t2,t1
  400194:	2d6b0001 	sltiu	t3,t3,1
  400198:	afa8004c 	sw	t0,76(sp)
  40019c:	afab0028 	sw	t3,40(sp)
  4001a0:	8fa80028 	lw	t0,40(sp)
  4001a4:	00000000 	nop
  4001a8:	11000008 	beqz	t0,4001cc <elseStart_2_oneLif>
  4001ac:	00000000 	nop
  4001b0:	24090006 	li	t1,6
  4001b4:	afa90024 	sw	t1,36(sp)
  4001b8:	8fa80024 	lw	t0,36(sp)
  4001bc:	00000000 	nop
  4001c0:	afa80030 	sw	t0,48(sp)
  4001c4:	10000006 	b	4001e0 <elseEnd_3_oneLif>
  4001c8:	00000000 	nop

004001cc <elseStart_2_oneLif>:
  4001cc:	2408004e 	li	t0,78
  4001d0:	afa80020 	sw	t0,32(sp)
  4001d4:	8fa80020 	lw	t0,32(sp)
  4001d8:	00000000 	nop
  4001dc:	afa80030 	sw	t0,48(sp)

004001e0 <elseEnd_3_oneLif>:
  4001e0:	8fa80030 	lw	t0,48(sp)
  4001e4:	00000000 	nop
  4001e8:	8fa9004c 	lw	t1,76(sp)
  4001ec:	00000000 	nop
  4001f0:	01095023 	subu	t2,t0,t1
  4001f4:	afa80034 	sw	t0,52(sp)
  4001f8:	afaa001c 	sw	t2,28(sp)
  4001fc:	8fa8001c 	lw	t0,28(sp)
  400200:	00000000 	nop
  400204:	01001025 	move	v0,t0
  400208:	10000001 	b	400210 <EXIT_oneLif>
  40020c:	00000000 	nop

00400210 <EXIT_oneLif>:
  400210:	8fbf0014 	lw	ra,20(sp)
  400214:	27bd0058 	addiu	sp,sp,88
  400218:	03e00008 	jr	ra
  40021c:	00000000 	nop
