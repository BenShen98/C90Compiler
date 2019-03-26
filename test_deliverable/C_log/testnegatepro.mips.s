
test_deliverable/C_log/testnegatepro.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <testnegatepro>:
  400110:	27bdffc8 	addiu	sp,sp,-56
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080008 	li	t0,8
  40011c:	afa80030 	sw	t0,48(sp)
  400120:	8fa80030 	lw	t0,48(sp)
  400124:	00000000 	nop
  400128:	24090006 	li	t1,6
  40012c:	afa80034 	sw	t0,52(sp)
  400130:	afa90028 	sw	t1,40(sp)
  400134:	8fa80028 	lw	t0,40(sp)
  400138:	00000000 	nop
  40013c:	8fa90034 	lw	t1,52(sp)
  400140:	00000000 	nop
  400144:	01285021 	addu	t2,t1,t0
  400148:	afa8002c 	sw	t0,44(sp)
  40014c:	afaa0020 	sw	t2,32(sp)
  400150:	8fa80020 	lw	t0,32(sp)
  400154:	00000000 	nop
  400158:	afa80024 	sw	t0,36(sp)
  40015c:	00084027 	nor	t0,zero,t0
  400160:	afa8001c 	sw	t0,28(sp)
  400164:	8fa8001c 	lw	t0,28(sp)
  400168:	00000000 	nop
  40016c:	01001025 	move	v0,t0
  400170:	10000001 	b	400178 <EXIT_testnegatepro>
  400174:	00000000 	nop

00400178 <EXIT_testnegatepro>:
  400178:	8fbf0014 	lw	ra,20(sp)
  40017c:	27bd0038 	addiu	sp,sp,56
  400180:	03e00008 	jr	ra
  400184:	00000000 	nop
	...
