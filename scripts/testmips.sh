#!/bin/bash

source scripts/config.sh

#make dir
rm -rf ${OUTPUT}
rm -rf ${EXEC}
rm -rf ${DUMP}
mkdir -p ${OUTPUT}
mkdir -p ${EXEC}
mkdir -p ${DUMP}
PASS=0
COUNT=0

#select compiler to be tested
if [[ "$1" != "" ]] ; then
    TESTCOMPILER="$1"
else
    TESTCOMPILER="bin/c_compiler"
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
  ${TESTCOMPILER} -S $i -o ${OUTPUT}/${base}.s 2> ${DUMP}/${base}.stderr 1> ${DUMP}/${base}.stdout
  #${MIPS_CC} ${MIPSFLAG} -S $i -o ${OUTPUT}/${base}.s 2> ${DUMP}/${base}.stderr 1> ${DUMP}/${base}.stdout

  #GCC assemble .s to object file
  ${MIPS_CC} ${MIPSFLAG} -c ${OUTPUT}/${base}.s -o ${OUTPUT}/${base}.o

  #Generate disassembly
  ${MIPS_CC} ${MIPS_CPPFLAGS} ${MIPS_LDFLAGS} ${OUTPUT}/${base}.o -o ${DUMP}/${base}.elf
  ${MIPS_OBJDUMP} -j .text -D ${DUMP}/${base}.elf > ${DUMP}/${base}.mips.s

  #Link object file with test driver using gcc MIPS FLAG on
  ${MIPS_CC} ${MIPSFLAG} -static -o ${EXEC}/${base} ${OUTPUT}/${base}.o ${TESTDRIVER}/${base}.c

  #Run execuable on QEMU virtual
  qemu-mips ${EXEC}/${base}
  RETURNCODE=$?

  #Check return code

  if [[ "$RETURNCODE" -eq "0" ]];then
    let "PASS++"
    echo "=>PASS TEST ${base}.c"
    printf "\n\n"
  else

    #print debug info ONLY when test FAIL
    echo "********************TEST FAIL ${base}********************"
    echo "=>FAIL TEST ${base}.c"
    printf "\n\n"
    echo "## C Input: "
    cat ${TESTDIRECTORY}/${base}.c
    printf "\n"
    echo "## C Driver: "
    cat ${TESTDRIVER}/${base}.c
    printf "\n"
    echo "## Assembly: "
    cat ${OUTPUT}/${base}.s
    printf "\n"
    echo "## Assembly Disassembly:"
    cat ${DUMP}/${base}.mips.s
    printf "\n\n"
    printf "********************END FAIL ${base}********************\n\n\n"
  fi


  #increment counter
  let "COUNT++"
done


FAIL=$(( ${COUNT}-${PASS} ))
echo "Exit with ${PASS} test case passed"
exit ${FAIL}
