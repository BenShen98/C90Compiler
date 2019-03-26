
test_deliverable/C_log/func_4arg.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400130 <f1>:
  400130:	27bdffe0 	addiu	sp,sp,-32
  400134:	afbf0014 	sw	ra,20(sp)
  400138:	afa40020 	sw	a0,32(sp)
  40013c:	8fa80020 	lw	t0,32(sp)
  400140:	00000000 	nop
  400144:	01084821 	addu	t1,t0,t0
  400148:	afa9001c 	sw	t1,28(sp)
  40014c:	8fa8001c 	lw	t0,28(sp)
  400150:	00000000 	nop
  400154:	01001025 	move	v0,t0
  400158:	10000001 	b	400160 <EXIT_f1>
  40015c:	00000000 	nop

00400160 <EXIT_f1>:
  400160:	8fbf0014 	lw	ra,20(sp)
  400164:	27bd0020 	addiu	sp,sp,32
  400168:	03e00008 	jr	ra
  40016c:	00000000 	nop

00400170 <f3>:
  400170:	27bdffe0 	addiu	sp,sp,-32
  400174:	afbf0014 	sw	ra,20(sp)
  400178:	afa40020 	sw	a0,32(sp)
  40017c:	afa50024 	sw	a1,36(sp)
  400180:	afa60028 	sw	a2,40(sp)
  400184:	8fa40024 	lw	a0,36(sp)
  400188:	00000000 	nop
  40018c:	8f998018 	lw	t9,-32744(gp)
  400190:	0411ffe7 	bal	400130 <f1>
  400194:	00000000 	nop
  400198:	00404025 	move	t0,v0
  40019c:	afa8001c 	sw	t0,28(sp)
  4001a0:	8fa8001c 	lw	t0,28(sp)
  4001a4:	00000000 	nop
  4001a8:	01001025 	move	v0,t0
  4001ac:	10000001 	b	4001b4 <EXIT_f3>
  4001b0:	00000000 	nop

004001b4 <EXIT_f3>:
  4001b4:	8fbf0014 	lw	ra,20(sp)
  4001b8:	27bd0020 	addiu	sp,sp,32
  4001bc:	03e00008 	jr	ra
  4001c0:	00000000 	nop
	...
