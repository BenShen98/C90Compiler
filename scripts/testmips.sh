#!/bin/bash

source scripts/config.sh

#make dir
rm -rf ${OUTPUT}
rm -rf ${EXEC}
rm -rf ${DUMP}
mkdir -p ${OUTPUT}
mkdir -p ${EXEC}
mkdir -p ${DUMP}
mkdir -p ${ANSI_BIN}
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

  echo "********************TEST ${base}********************"


  #Compile .c to .s using TESTCOMPILER
  ${TESTCOMPILER} -S $i -o ${OUTPUT}/${base}.s 2> ${DUMP}/${base}.stderr 1> ${DUMP}/${base}.stdout
  #${MIPS_CC} ${MIPS_FLAGS} -S $i -o ${OUTPUT}/${base}.s 2> ${DUMP}/${base}.stderr 1> ${DUMP}/${base}.stdout

  #GCC assemble .s to object file
  ${MIPS_CC} ${MIPS_FLAGS} -c ${OUTPUT}/${base}.s -o ${OUTPUT}/${base}.o

  #Generate disassembly (for debug log)
  ${MIPS_CC} ${MIPS_FLAGS} ${MIPS_LDFLAGS} ${OUTPUT}/${base}.o -o ${DUMP}/${base}.elf
  ${MIPS_OBJDUMP} -j .text -D ${DUMP}/${base}.elf > ${DUMP}/${base}.mips.s

  #Link object file, test driver, setup file using gcc MIPS FLAG on
  ${MIPS_CC} ${MIPS_FLAGS} ${MIPS_LINK_FLAGS} -o  ${EXEC}/${base} ${ABI_COMPLIANCE_SRC} ${OUTPUT}/${base}.o ${TESTDRIVER}/${base}.c

  #Run execuable on QEMU virtual
  qemu-mips ${EXEC}/${base}
  RETURNCODE=$?

  #Check return code

  if [[ "$RETURNCODE" -eq "0" ]];then
    let "PASS++"
    echo "=>PASS TEST ${base}.c, get ${RETURNCODE}"
    printf "\n\n"
  else

    #print debug info ONLY when test FAIL
    echo "=>FAIL TEST ${base}.c, get ${RETURNCODE}"
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
  fi


  #increment counter
  let "COUNT++"
done


FAIL=$(( ${COUNT}-${PASS} ))
echo "Exit with [ ${PASS} / ${COUNT} ] test case passed"
exit ${FAIL}
