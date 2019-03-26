
test_deliverable/C_log/muti_func_noarg.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400130 <f>:
  400130:	27bdffd8 	addiu	sp,sp,-40
  400134:	afbf0014 	sw	ra,20(sp)
  400138:	8f998018 	lw	t9,-32744(gp)
  40013c:	04110014 	bal	400190 <f1>
  400140:	00000000 	nop
  400144:	00404025 	move	t0,v0
  400148:	afa80024 	sw	t0,36(sp)
  40014c:	8f99801c 	lw	t9,-32740(gp)
  400150:	0411001c 	bal	4001c4 <f2>
  400154:	00000000 	nop
  400158:	00404025 	move	t0,v0
  40015c:	8fa90024 	lw	t1,36(sp)
  400160:	00000000 	nop
  400164:	01285021 	addu	t2,t1,t0
  400168:	afaa001c 	sw	t2,28(sp)
  40016c:	8fa8001c 	lw	t0,28(sp)
  400170:	00000000 	nop
  400174:	01001025 	move	v0,t0
  400178:	10000001 	b	400180 <EXIT_f>
  40017c:	00000000 	nop

00400180 <EXIT_f>:
  400180:	8fbf0014 	lw	ra,20(sp)
  400184:	27bd0028 	addiu	sp,sp,40
  400188:	03e00008 	jr	ra
  40018c:	00000000 	nop

00400190 <f1>:
  400190:	27bdffd8 	addiu	sp,sp,-40
  400194:	afbf0014 	sw	ra,20(sp)
  400198:	24080001 	li	t0,1
  40019c:	afa80024 	sw	t0,36(sp)
  4001a0:	8fa80024 	lw	t0,36(sp)
  4001a4:	00000000 	nop
  4001a8:	01001025 	move	v0,t0
  4001ac:	10000001 	b	4001b4 <EXIT_f1>
  4001b0:	00000000 	nop

004001b4 <EXIT_f1>:
  4001b4:	8fbf0014 	lw	ra,20(sp)
  4001b8:	27bd0028 	addiu	sp,sp,40
  4001bc:	03e00008 	jr	ra
  4001c0:	00000000 	nop

004001c4 <f2>:
  4001c4:	27bdffd8 	addiu	sp,sp,-40
  4001c8:	afbf0014 	sw	ra,20(sp)
  4001cc:	24080005 	li	t0,5
  4001d0:	afa80020 	sw	t0,32(sp)
  4001d4:	8fa80020 	lw	t0,32(sp)
  4001d8:	00000000 	nop
  4001dc:	afa80024 	sw	t0,36(sp)
  4001e0:	8fa80024 	lw	t0,36(sp)
  4001e4:	00000000 	nop
  4001e8:	01001025 	move	v0,t0
  4001ec:	10000001 	b	4001f4 <EXIT_f2>
  4001f0:	00000000 	nop

004001f4 <EXIT_f2>:
  4001f4:	8fbf0014 	lw	ra,20(sp)
  4001f8:	27bd0028 	addiu	sp,sp,40
  4001fc:	03e00008 	jr	ra
  400200:	00000000 	nop
	...
