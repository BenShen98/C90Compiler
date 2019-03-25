
lifloat.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

004000f0 <_ftext>:
  4000f0:	3c014020 	lui	at,0x4020
  4000f4:	44810800 	mtc1	at,$f1
  4000f8:	10000004 	b	40010c <x>
  4000fc:	00000000 	nop
  400100:	3c013ff0 	lui	at,0x3ff0
  400104:	44812800 	mtc1	at,$f5
  400108:	44802000 	mtc1	zero,$f4

0040010c <x>:
  40010c:	8f818018 	lw	at,-32744(gp)
  400110:	00000000 	nop
  400114:	c4250120 	lwc1	$f5,288(at)
  400118:	c4240124 	lwc1	$f4,292(at)
  40011c:	00000000 	nop
