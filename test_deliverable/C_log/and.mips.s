
test_deliverable/C_log/and.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <testand>:
  400110:	27bdffd0 	addiu	sp,sp,-48
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080002 	li	t0,2
  40011c:	afa80028 	sw	t0,40(sp)
  400120:	8fa80028 	lw	t0,40(sp)
  400124:	00000000 	nop
  400128:	24090001 	li	t1,1
  40012c:	afa8002c 	sw	t0,44(sp)
  400130:	afa90020 	sw	t1,32(sp)
  400134:	8fa80020 	lw	t0,32(sp)
  400138:	00000000 	nop
  40013c:	8fa9002c 	lw	t1,44(sp)
  400140:	00000000 	nop
  400144:	01285024 	and	t2,t1,t0
  400148:	afa80024 	sw	t0,36(sp)
  40014c:	afaa001c 	sw	t2,28(sp)
  400150:	8fa8001c 	lw	t0,28(sp)
  400154:	00000000 	nop
  400158:	01001025 	move	v0,t0
  40015c:	10000001 	b	400164 <EXIT_testand>
  400160:	00000000 	nop

00400164 <EXIT_testand>:
  400164:	8fbf0014 	lw	ra,20(sp)
  400168:	27bd0030 	addiu	sp,sp,48
  40016c:	03e00008 	jr	ra
  400170:	00000000 	nop
	...
