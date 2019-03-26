
test_deliverable/C_log/sizeof.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <f>:
  400110:	27bdff70 	addiu	sp,sp,-144
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	8fa80020 	lw	t0,32(sp)
  40011c:	00000000 	nop
  400120:	27a80024 	addiu	t0,sp,36
  400124:	2409006c 	li	t1,108
  400128:	afa80020 	sw	t0,32(sp)
  40012c:	afa9001c 	sw	t1,28(sp)
  400130:	8fa8001c 	lw	t0,28(sp)
  400134:	00000000 	nop
  400138:	01001025 	move	v0,t0
  40013c:	10000001 	b	400144 <EXIT_f>
  400140:	00000000 	nop

00400144 <EXIT_f>:
  400144:	8fbf0014 	lw	ra,20(sp)
  400148:	27bd0090 	addiu	sp,sp,144
  40014c:	03e00008 	jr	ra
  400150:	00000000 	nop
	...
