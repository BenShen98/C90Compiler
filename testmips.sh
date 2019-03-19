#!/bin/bash

#FOR LINUX
MIPS_CC="mips-linux-gnu-gcc"
MIPS_OBJCOPY="mips-linux-gnu-objcopy"
MIPS_OBJDUMP="mips-linux-gnu-objdump"

#FOR MAC WITH BREW
#MIPS_CC="mips-linux-gnu-gcc"
#MIPS_OBJCOPY="mips-linux-gnu-objcopy"
#MIPS_OBJDUMP="mips-linux-gnu-objdump"

#MIPS flag
MIPS_CPPFLAGS="-mfp32"
MIPS_LDFLAGS="-nostdlib -mfp32  -static --entry=0000000000400110" #entry address was used to remote warning

#testbench config
TESTDIRECTORY="test/c_test"
TESTDRIVER="test/c_driver_test"
OUTPUT="test/C_output"
EXEC="test/C_driver_exec"
DUMP="test/dump"

#make dir
mkdir -p ${OUTPUT}
mkdir -p ${EXEC}
mkdir -p ${DUMP}
PASS=0
COUNT=0

#select compiler to be tested
if [[ "$1" != "" ]] ; then
    COMPILER="$1"
else
    COMPILER="bin/c_compiler"
fi


#check if test case exists
if [ ! -d "$TESTDIRECTORY" ]; then
  # Control will enter here if $DIRECTORY doesn't exist.
  echo "Test case directory does not exist"
  exit -1
fi
if [ ! -d "$TESTDRIVER" ]; then
  # Control will enter here if $DIRECTORY doesn't exist.
  echo "Test driver directory does not exist"
  exit -1
fi

#run test case
for i in ${TESTDIRECTORY}/*.c; do
  base=$(basename $i)
  base=${base%.c}

  #Run compiler on test case
  #${COMPILER} -S $i -o ${OUTPUT}/${base}.s
  ${MIPS_CC} ${MIPSFLAG} -S $i -o ${OUTPUT}/${base}.s

  #GCC assemble .s to object file
  ${MIPS_CC} ${MIPSFLAG} -c ${OUTPUT}/${base}.s -o ${OUTPUT}/${base}.o

  #Link object file with test driver using gcc MIPS FLAG on
  ${MIPS_CC} ${MIPSFLAG} -static -o ${EXEC}/${base} ${OUTPUT}/${base}.o ${TESTDRIVER}/${base}.c

  #Run execuable on QEMU virtual
  qemu-mips ${EXEC}/${base}
  RETURNCODE=$?

  #Generate disassembly
  ${MIPS_CC} ${MIPS_CPPFLAGS} -c ${OUTPUT}/${base}.s -o ${DUMP}/${base}.o
  ${MIPS_CC} ${MIPS_CPPFLAGS} ${MIPS_LDFLAGS} ${DUMP}/${base}.o -o ${DUMP}/${base}.elf
  ${MIPS_OBJDUMP} -j .text -D ${DUMP}/${base}.elf > ${DUMP}/${base}.mips.s

  #Check return code
  if [[ "$RETURNCODE" -eq "0" ]];then
    let "PASS++"
    echo "=>PASS TEST ${base}.c"
    printf "\n\n"
  else
    echo "=>FAIL TEST ${base}.c"
    printf "\n\n"

    #print debug info ONLY when test FAIL
    echo "********************TEST ${base}.c********************"
    echo "C Input: "
    cat ${TESTDIRECTORY}/${base}.c
    printf "\n"
    echo "C Driver: "
    cat ${TESTDRIVER}/${base}.c
    printf "\n"
    echo "Assembly Output:"
    cat ${DUMP}/${base}.mips.s
    echo "********************END ${base}.c********************"
    printf "\n\n"

  fi

  #increment counter
  let "COUNT++"
done


FAIL=$(( ${COUNT}-${PASS} ))
echo "Exit with ${PASS} test case passed"
echo "*********************************************************"
exit ${FAIL}
