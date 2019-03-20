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
MIPS_CPPFLAGS="-mfp32"
#MIPS_LDFLAGS="-nostdlib -mfp32  -static --entry=0000000000400110" #entry address was used to remote warning
MIPS_LDFLAGS="-nostdlib -mfp32  -static --entry=0000000000400110" #entry address was used to remote warning

#testbench config
TESTDIRECTORY="test_deliverable/testcases"
TESTDRIVER="test_deliverable/C_driver_test"
OUTPUT="test_deliverable/bin/C_output"
EXEC="test_deliverable/bin/C_mips_bin"
DUMP="test_deliverable/bin/C_log"
ANSI_BIN="test_deliverable/bin/ansi"
