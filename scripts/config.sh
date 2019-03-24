#FOR LINUX
MIPS_CC="mips-linux-gnu-gcc"
MIPS_OBJCOPY="mips-linux-gnu-objcopy"
MIPS_OBJDUMP="mips-linux-gnu-objdump"

#FOR MAC WITH BREW
#MIPS_CC="mips-linux-gnu-gcc"
#MIPS_OBJCOPY="mips-linux-gnu-objcopy"
#MIPS_OBJDUMP="mips-linux-gnu-objdump"

#CHECK TEST CASE IS ANSI
GCC_ANSI="gcc -ansi"

#MIPS flag
MIPS_LINK_FLAGS="-static -ansi"
MIPS_FLAGS="-mfp32"
MIPS_LDFLAGS="-nostdlib -mfp32  -static --entry=0000000000400110" #for disassembly

#testbench config
TEST_ROOT=test

TESTDIRECTORY="${TEST_ROOT}/C_test"
TESTDRIVER="${TEST_ROOT}/C_driver_test"
OUTPUT="${TEST_ROOT}/C_output"
EXEC="${TEST_ROOT}/C_mips_bin"
DUMP="${TEST_ROOT}/C_log"
ANSI_BIN="${TEST_ROOT}/ansi"

ABI_COMPLIANCE_SRC=${TEST_ROOT}/abi.s
ABI_COMPLIANCE_C=${TEST_ROOT}/abi.c