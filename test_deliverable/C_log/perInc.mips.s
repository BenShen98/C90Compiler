
test_deliverable/C_log/perInc.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <perInc>:
  400110:	27bdffd0 	addiu	sp,sp,-48
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080000 	li	t0,0
  40011c:	afa80028 	sw	t0,40(sp)
  400120:	8fa80028 	lw	t0,40(sp)
  400124:	00000000 	nop
  400128:	24090000 	li	t1,0
  40012c:	afa8002c 	sw	t0,44(sp)
  400130:	afa90020 	sw	t1,32(sp)
  400134:	8fa80020 	lw	t0,32(sp)
  400138:	00000000 	nop
  40013c:	8fa9002c 	lw	t1,44(sp)
  400140:	00000000 	nop
  400144:	21290001 	addi	t1,t1,1
  400148:	afa9002c 	sw	t1,44(sp)
  40014c:	afa80024 	sw	t0,36(sp)
  400150:	8fa8002c 	lw	t0,44(sp)
  400154:	00000000 	nop
  400158:	8fa9002c 	lw	t1,44(sp)
  40015c:	00000000 	nop
  400160:	01285021 	addu	t2,t1,t0
  400164:	afa80024 	sw	t0,36(sp)
  400168:	afaa001c 	sw	t2,28(sp)
  40016c:	8fa8001c 	lw	t0,28(sp)
  400170:	00000000 	nop
  400174:	01001025 	move	v0,t0
  400178:	10000001 	b	400180 <EXIT_perInc>
  40017c:	00000000 	nop

00400180 <EXIT_perInc>:
  400180:	8fbf0014 	lw	ra,20(sp)
  400184:	27bd0030 	addiu	sp,sp,48
  400188:	03e00008 	jr	ra
  40018c:	00000000 	nop
