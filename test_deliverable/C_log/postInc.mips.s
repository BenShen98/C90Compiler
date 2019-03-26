
test_deliverable/C_log/postInc.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <postInc>:
  400110:	27bdffc8 	addiu	sp,sp,-56
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080000 	li	t0,0
  40011c:	afa80030 	sw	t0,48(sp)
  400120:	8fa80030 	lw	t0,48(sp)
  400124:	00000000 	nop
  400128:	24090000 	li	t1,0
  40012c:	afa80034 	sw	t0,52(sp)
  400130:	afa90028 	sw	t1,40(sp)
  400134:	8fa80028 	lw	t0,40(sp)
  400138:	00000000 	nop
  40013c:	8fa90034 	lw	t1,52(sp)
  400140:	00000000 	nop
  400144:	212a0001 	addi	t2,t1,1
  400148:	afa8002c 	sw	t0,44(sp)
  40014c:	afa90024 	sw	t1,36(sp)
  400150:	afaa0034 	sw	t2,52(sp)
  400154:	8fa80024 	lw	t0,36(sp)
  400158:	00000000 	nop
  40015c:	8fa90034 	lw	t1,52(sp)
  400160:	00000000 	nop
  400164:	01285021 	addu	t2,t1,t0
  400168:	afa8002c 	sw	t0,44(sp)
  40016c:	afaa0020 	sw	t2,32(sp)
  400170:	8fa80020 	lw	t0,32(sp)
  400174:	00000000 	nop
  400178:	01001025 	move	v0,t0
  40017c:	10000001 	b	400184 <EXIT_postInc>
  400180:	00000000 	nop

00400184 <EXIT_postInc>:
  400184:	8fbf0014 	lw	ra,20(sp)
  400188:	27bd0038 	addiu	sp,sp,56
  40018c:	03e00008 	jr	ra
  400190:	00000000 	nop
	...
