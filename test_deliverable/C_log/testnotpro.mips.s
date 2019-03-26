
test_deliverable/C_log/testnotpro.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <testnotpro>:
  400110:	27bdffd0 	addiu	sp,sp,-48
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080001 	li	t0,1
  40011c:	00084023 	negu	t0,t0
  400120:	afa80024 	sw	t0,36(sp)
  400124:	8fa80024 	lw	t0,36(sp)
  400128:	00000000 	nop
  40012c:	afa8002c 	sw	t0,44(sp)
  400130:	2d080001 	sltiu	t0,t0,1
  400134:	310800ff 	andi	t0,t0,0xff
  400138:	afa80020 	sw	t0,32(sp)
  40013c:	8fa80020 	lw	t0,32(sp)
  400140:	00000000 	nop
  400144:	01001025 	move	v0,t0
  400148:	10000001 	b	400150 <EXIT_testnotpro>
  40014c:	00000000 	nop

00400150 <EXIT_testnotpro>:
  400150:	8fbf0014 	lw	ra,20(sp)
  400154:	27bd0030 	addiu	sp,sp,48
  400158:	03e00008 	jr	ra
  40015c:	00000000 	nop
