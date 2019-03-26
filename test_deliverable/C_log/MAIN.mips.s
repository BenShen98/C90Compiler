
test_deliverable/C_log/MAIN.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <main>:
  400110:	27bdffe0 	addiu	sp,sp,-32
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080000 	li	t0,0
  40011c:	afa8001c 	sw	t0,28(sp)
  400120:	8fa8001c 	lw	t0,28(sp)
  400124:	00000000 	nop
  400128:	01001025 	move	v0,t0
  40012c:	10000001 	b	400134 <EXIT_main>
  400130:	00000000 	nop

00400134 <EXIT_main>:
  400134:	8fbf0014 	lw	ra,20(sp)
  400138:	27bd0020 	addiu	sp,sp,32
  40013c:	03e00008 	jr	ra
  400140:	00000000 	nop
	...
