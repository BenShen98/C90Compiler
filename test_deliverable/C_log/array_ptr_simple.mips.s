
test_deliverable/C_log/array_ptr_simple.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <f>:
  400110:	27bdff90 	addiu	sp,sp,-112
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	8fa8005c 	lw	t0,92(sp)
  40011c:	00000000 	nop
  400120:	27a80060 	addiu	t0,sp,96
  400124:	24090000 	li	t1,0
  400128:	240a0004 	li	t2,4
  40012c:	012a0018 	mult	t1,t2
  400130:	00005812 	mflo	t3
  400134:	010b4821 	addu	t1,t0,t3
  400138:	afa8005c 	sw	t0,92(sp)
  40013c:	afa9004c 	sw	t1,76(sp)
  400140:	afaa0054 	sw	t2,84(sp)
  400144:	8fa8004c 	lw	t0,76(sp)
  400148:	00000000 	nop
  40014c:	24090002 	li	t1,2
  400150:	8faa0044 	lw	t2,68(sp)
  400154:	00000000 	nop
  400158:	27aa0060 	addiu	t2,sp,96
  40015c:	240b0004 	li	t3,4
  400160:	012b0018 	mult	t1,t3
  400164:	00006012 	mflo	t4
  400168:	018a4821 	addu	t1,t4,t2
  40016c:	240c0005 	li	t4,5
  400170:	afa8006c 	sw	t0,108(sp)
  400174:	afa90038 	sw	t1,56(sp)
  400178:	afaa0044 	sw	t2,68(sp)
  40017c:	afab0040 	sw	t3,64(sp)
  400180:	afac0034 	sw	t4,52(sp)
  400184:	8fa80038 	lw	t0,56(sp)
  400188:	00000000 	nop
  40018c:	8fa90034 	lw	t1,52(sp)
  400190:	00000000 	nop
  400194:	ad090000 	sw	t1,0(t0)
  400198:	240a0002 	li	t2,2
  40019c:	8fab006c 	lw	t3,108(sp)
  4001a0:	00000000 	nop
  4001a4:	240c0004 	li	t4,4
  4001a8:	014c0018 	mult	t2,t4
  4001ac:	00006812 	mflo	t5
  4001b0:	016d5021 	addu	t2,t3,t5
  4001b4:	afaa0024 	sw	t2,36(sp)
  4001b8:	afac002c 	sw	t4,44(sp)
  4001bc:	8fa80024 	lw	t0,36(sp)
  4001c0:	00000000 	nop
  4001c4:	8d080000 	lw	t0,0(t0)
  4001c8:	00000000 	nop
  4001cc:	01001025 	move	v0,t0
  4001d0:	10000001 	b	4001d8 <EXIT_f>
  4001d4:	00000000 	nop

004001d8 <EXIT_f>:
  4001d8:	8fbf0014 	lw	ra,20(sp)
  4001dc:	27bd0070 	addiu	sp,sp,112
  4001e0:	03e00008 	jr	ra
  4001e4:	00000000 	nop
	...
