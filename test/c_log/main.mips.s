
test/c_log/main.elf:     file format elf32-tradbigmips


Disassembly of section .text:

00400110 <_ftext>:
  400110:	27bdffe0 	addiu	sp,sp,-32
  400114:	afbf0014 	sw	ra,20(sp)
  400118:	24080000 	li	t0,0
  40011c:	01001025 	move	v0,t0
  400120:	10000002 	b	40012c <EXIT_main>
  400124:	00000000 	nop
  400128:	afa80018 	sw	t0,24(sp)

0040012c <EXIT_main>:
  40012c:	8fbf0014 	lw	ra,20(sp)
  400130:	27bd0020 	addiu	sp,sp,32
  400134:	03e00008 	jr	ra
  400138:	00000000 	nop
  40013c:	00000000 	nop
