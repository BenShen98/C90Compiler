
test_deliverable/C_log/forinc.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <testforinc>:
  400110:	27bdffc0 	addiu	sp,sp,-64
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080000 	li	t0,0
  40011c:	afa80038 	sw	t0,56(sp)
  400120:	8fa80038 	lw	t0,56(sp)
  400124:	00000000 	nop
  400128:	24090000 	li	t1,0
  40012c:	240a0000 	li	t2,0
  400130:	afa8003c 	sw	t0,60(sp)
  400134:	afa90034 	sw	t1,52(sp)
  400138:	afaa0030 	sw	t2,48(sp)
  40013c:	8fa80030 	lw	t0,48(sp)
  400140:	00000000 	nop
  400144:	afa80034 	sw	t0,52(sp)

00400148 <ItrCondition_0_testforinc>:
  400148:	24080000 	li	t0,0
  40014c:	11000014 	beqz	t0,4001a0 <ItrEnd_1_testforinc>
  400150:	00000000 	nop
  400154:	afa8002c 	sw	t0,44(sp)
  400158:	24080001 	li	t0,1
  40015c:	afa8001c 	sw	t0,28(sp)
  400160:	8fa8003c 	lw	t0,60(sp)
  400164:	00000000 	nop
  400168:	8fa9001c 	lw	t1,28(sp)
  40016c:	00000000 	nop
  400170:	01095021 	addu	t2,t0,t1

00400174 <conti_2_testforinc>:
  400174:	afaa003c 	sw	t2,60(sp)
  400178:	24080001 	li	t0,1
  40017c:	8fa90034 	lw	t1,52(sp)
  400180:	00000000 	nop
  400184:	01285021 	addu	t2,t1,t0
  400188:	afaa0024 	sw	t2,36(sp)
  40018c:	8fa80024 	lw	t0,36(sp)
  400190:	00000000 	nop
  400194:	afa80034 	sw	t0,52(sp)
  400198:	1000ffeb 	b	400148 <ItrCondition_0_testforinc>
  40019c:	00000000 	nop

004001a0 <ItrEnd_1_testforinc>:
  4001a0:	8fa8003c 	lw	t0,60(sp)
  4001a4:	00000000 	nop
  4001a8:	01001025 	move	v0,t0
  4001ac:	10000001 	b	4001b4 <EXIT_testforinc>
  4001b0:	00000000 	nop

004001b4 <EXIT_testforinc>:
  4001b4:	8fbf0014 	lw	ra,20(sp)
  4001b8:	27bd0040 	addiu	sp,sp,64
  4001bc:	03e00008 	jr	ra
  4001c0:	00000000 	nop
	...
