
test_deliverable/C_log/testnegate.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <testnegate>:
  400110:	27bdffd8 	addiu	sp,sp,-40
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080001 	li	t0,1
  40011c:	afa80020 	sw	t0,32(sp)
  400120:	8fa80020 	lw	t0,32(sp)
  400124:	00000000 	nop
  400128:	afa80024 	sw	t0,36(sp)
  40012c:	2d080001 	sltiu	t0,t0,1
  400130:	310800ff 	andi	t0,t0,0xff
  400134:	afa8001c 	sw	t0,28(sp)
  400138:	8fa8001c 	lw	t0,28(sp)
  40013c:	00000000 	nop
  400140:	01001025 	move	v0,t0
  400144:	10000001 	b	40014c <EXIT_testnegate>
  400148:	00000000 	nop

0040014c <EXIT_testnegate>:
  40014c:	8fbf0014 	lw	ra,20(sp)
  400150:	27bd0028 	addiu	sp,sp,40
  400154:	03e00008 	jr	ra
  400158:	00000000 	nop
  40015c:	00000000 	nop
