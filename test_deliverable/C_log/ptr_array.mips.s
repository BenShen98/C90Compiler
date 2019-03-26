
test_deliverable/C_log/ptr_array.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <f>:
  400110:	27bdff98 	addiu	sp,sp,-104
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	8fa8004c 	lw	t0,76(sp)
  40011c:	00000000 	nop
  400120:	27a80054 	addiu	t0,sp,84
  400124:	afa8004c 	sw	t0,76(sp)
  400128:	8fa8004c 	lw	t0,76(sp)
  40012c:	00000000 	nop
  400130:	24090001 	li	t1,1
  400134:	afa80050 	sw	t0,80(sp)
  400138:	8d080000 	lw	t0,0(t0)
  40013c:	00000000 	nop
  400140:	240a0004 	li	t2,4
  400144:	012a0018 	mult	t1,t2
  400148:	00005812 	mflo	t3
  40014c:	010b4821 	addu	t1,t0,t3
  400150:	24080006 	li	t0,6
  400154:	afa80034 	sw	t0,52(sp)
  400158:	afa90038 	sw	t1,56(sp)
  40015c:	afaa0040 	sw	t2,64(sp)
  400160:	8fa80038 	lw	t0,56(sp)
  400164:	00000000 	nop
  400168:	8fa90034 	lw	t1,52(sp)
  40016c:	00000000 	nop
  400170:	ad090000 	sw	t1,0(t0)
  400174:	240a0001 	li	t2,1
  400178:	8fab0050 	lw	t3,80(sp)
  40017c:	00000000 	nop
  400180:	8d6b0000 	lw	t3,0(t3)
  400184:	00000000 	nop
  400188:	240c0004 	li	t4,4
  40018c:	014c0018 	mult	t2,t4
  400190:	00006812 	mflo	t5
  400194:	016d5021 	addu	t2,t3,t5
  400198:	afaa0020 	sw	t2,32(sp)
  40019c:	afac0028 	sw	t4,40(sp)
  4001a0:	8fa80020 	lw	t0,32(sp)
  4001a4:	00000000 	nop
  4001a8:	8d080000 	lw	t0,0(t0)
  4001ac:	00000000 	nop
  4001b0:	01001025 	move	v0,t0
  4001b4:	10000001 	b	4001bc <EXIT_f>
  4001b8:	00000000 	nop

004001bc <EXIT_f>:
  4001bc:	8fbf0014 	lw	ra,20(sp)
  4001c0:	27bd0068 	addiu	sp,sp,104
  4001c4:	03e00008 	jr	ra
  4001c8:	00000000 	nop
  4001cc:	00000000 	nop
