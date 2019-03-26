
test_deliverable/C_log/ptr.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <f>:
  400110:	27bdffc8 	addiu	sp,sp,-56
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080005 	li	t0,5
  40011c:	afa80030 	sw	t0,48(sp)
  400120:	8fa80030 	lw	t0,48(sp)
  400124:	00000000 	nop
  400128:	24090000 	li	t1,0
  40012c:	afa80034 	sw	t0,52(sp)
  400130:	27a80034 	addiu	t0,sp,52
  400134:	afa80024 	sw	t0,36(sp)
  400138:	afa90028 	sw	t1,40(sp)
  40013c:	8fa80024 	lw	t0,36(sp)
  400140:	00000000 	nop
  400144:	2409000a 	li	t1,10
  400148:	afa8002c 	sw	t0,44(sp)
  40014c:	afa90020 	sw	t1,32(sp)
  400150:	8fa8002c 	lw	t0,44(sp)
  400154:	00000000 	nop
  400158:	8fa90020 	lw	t1,32(sp)
  40015c:	00000000 	nop
  400160:	ad090000 	sw	t1,0(t0)
  400164:	8fa8002c 	lw	t0,44(sp)
  400168:	00000000 	nop
  40016c:	8d080000 	lw	t0,0(t0)
  400170:	00000000 	nop
  400174:	01001025 	move	v0,t0
  400178:	10000001 	b	400180 <EXIT_f>
  40017c:	00000000 	nop

00400180 <EXIT_f>:
  400180:	8fbf0014 	lw	ra,20(sp)
  400184:	27bd0038 	addiu	sp,sp,56
  400188:	03e00008 	jr	ra
  40018c:	00000000 	nop
