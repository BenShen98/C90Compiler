
a.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <EXIT_para-0x20>:
10000000:	27bdffd8 	addiu	sp,sp,-40
10000004:	afbf0010 	sw	ra,16(sp)
10000008:	3c080001 	lui	t0,0x1
1000000c:	3508e240 	ori	t0,t0,0xe240
10000010:	240911d4 	li	t1,4564
10000014:	01095021 	addu	t2,t0,t1
10000018:	afa80020 	sw	t0,32(sp)
1000001c:	afaa0018 	sw	t2,24(sp)

10000020 <EXIT_para>:
10000020:	8fbf0010 	lw	ra,16(sp)
10000024:	27bd0028 	addiu	sp,sp,40
10000028:	03e00008 	jr	ra
1000002c:	00000000 	nop
