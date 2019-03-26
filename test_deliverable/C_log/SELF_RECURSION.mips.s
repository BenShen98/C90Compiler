
test_deliverable/C_log/SELF_RECURSION.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400130 <recadd>:
  400130:	27bdffc8 	addiu	sp,sp,-56
  400134:	afbf0014 	sw	ra,20(sp)
  400138:	afa40038 	sw	a0,56(sp)
  40013c:	24080001 	li	t0,1
  400140:	8fa90038 	lw	t1,56(sp)
  400144:	00000000 	nop
  400148:	0128502a 	slt	t2,t1,t0
  40014c:	afaa0030 	sw	t2,48(sp)
  400150:	8fa80030 	lw	t0,48(sp)
  400154:	00000000 	nop
  400158:	1100000a 	beqz	t0,400184 <elseStart_1_recadd>
  40015c:	00000000 	nop
  400160:	24080000 	li	t0,0
  400164:	afa8002c 	sw	t0,44(sp)
  400168:	8fa8002c 	lw	t0,44(sp)
  40016c:	00000000 	nop
  400170:	01001025 	move	v0,t0
  400174:	10000017 	b	4001d4 <EXIT_recadd>
  400178:	00000000 	nop
  40017c:	10000015 	b	4001d4 <EXIT_recadd>
  400180:	00000000 	nop

00400184 <elseStart_1_recadd>:
  400184:	24080001 	li	t0,1
  400188:	8fa90038 	lw	t1,56(sp)
  40018c:	00000000 	nop
  400190:	01285023 	subu	t2,t1,t0
  400194:	afaa0028 	sw	t2,40(sp)
  400198:	8fa40028 	lw	a0,40(sp)
  40019c:	00000000 	nop
  4001a0:	8f998018 	lw	t9,-32744(gp)
  4001a4:	0411ffe2 	bal	400130 <recadd>
  4001a8:	00000000 	nop
  4001ac:	00404025 	move	t0,v0
  4001b0:	8fa90038 	lw	t1,56(sp)
  4001b4:	00000000 	nop
  4001b8:	01285021 	addu	t2,t1,t0
  4001bc:	afaa0020 	sw	t2,32(sp)
  4001c0:	8fa80020 	lw	t0,32(sp)
  4001c4:	00000000 	nop
  4001c8:	01001025 	move	v0,t0
  4001cc:	10000001 	b	4001d4 <EXIT_recadd>
  4001d0:	00000000 	nop

004001d4 <EXIT_recadd>:
  4001d4:	8fbf0014 	lw	ra,20(sp)
  4001d8:	27bd0038 	addiu	sp,sp,56
  4001dc:	03e00008 	jr	ra
  4001e0:	00000000 	nop
	...
