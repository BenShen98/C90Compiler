
test_deliverable/C_log/addmix.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <addmix>:
  400110:	27bdffc8 	addiu	sp,sp,-56
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080006 	li	t0,6
  40011c:	afa80030 	sw	t0,48(sp)
  400120:	8fa80030 	lw	t0,48(sp)
  400124:	00000000 	nop
  400128:	24090001 	li	t1,1
  40012c:	00094823 	negu	t1,t1
  400130:	afa80034 	sw	t0,52(sp)
  400134:	afa90024 	sw	t1,36(sp)
  400138:	8fa80024 	lw	t0,36(sp)
  40013c:	00000000 	nop
  400140:	8fa90034 	lw	t1,52(sp)
  400144:	00000000 	nop
  400148:	01285021 	addu	t2,t1,t0
  40014c:	afa8002c 	sw	t0,44(sp)
  400150:	afaa0020 	sw	t2,32(sp)
  400154:	8fa80020 	lw	t0,32(sp)
  400158:	00000000 	nop
  40015c:	01001025 	move	v0,t0
  400160:	10000001 	b	400168 <EXIT_addmix>
  400164:	00000000 	nop

00400168 <EXIT_addmix>:
  400168:	8fbf0014 	lw	ra,20(sp)
  40016c:	27bd0038 	addiu	sp,sp,56
  400170:	03e00008 	jr	ra
  400174:	00000000 	nop
	...
