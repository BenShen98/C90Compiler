
MIPS_CC = mips-linux-gnu-gcc
MIPS_OBJCOPY = mips-linux-gnu-objcopy
MIPS_OBJDUMP = mips-linux-gnu-objdump

#MIPS_CC = mips-linux-musl-gcc
#MIPS_OBJCOPY = mips-linux-musl-objcopy
#MIPS_OBJDUMP = mips-linux-musl-objdump

MIPS_CPPFLAGS = -mfp32
MIPS_LDFLAGS = -nostdlib -mfp32  -static

#MIPS_CPPFLAGS = -W -Wall -O3 -fno-builtin -march=mips1 -mfp32
#MIPS_LDFLAGS = -nostdlib -Wl,-melf32btsmip -march=mips1 -nostartfiles -mno-check-zero-division -Wl,--gpsize=0 -static -Wl,-Bstatic -Wl,--build-id=none --entry=0000000010000000
#MIPS_Linker = ./linker.ld

%.mips.o: %.c
	$(MIPS_CC) $(MIPS_CPPFLAGS) -ansi -c $< -o $@

%.mips.o: %.s
	$(MIPS_CC) $(MIPS_CPPFLAGS) -c $< -o $@

%.mips.elf: %.mips.o
	$(MIPS_CC) $(MIPS_CPPFLAGS) $(MIPS_LDFLAGS) $< -o $@


%.mips.s : %.mips.elf
	$(MIPS_OBJDUMP) -j .text -D $< > $@
	cat $@
