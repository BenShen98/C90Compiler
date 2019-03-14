#!/bin/bash
MIPSFLAG="mips-linux-gnu-gcc -mfp32"
TESTDIRECTORY="test/c_test"
TESTDRIVER="test/c_driver_test"
OUTPUT="test/C_output"
EXEC="test/C_driver_exec"
mkdir -p ${OUTPUT}
mkdir -p ${EXEC}
PASS=0
COUNT=0

if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="bin/c_compiler"
fi

have_compiler=0
#check if bin/compiler exist or not
if [[ ! -f bin/c_compiler ]] ; then
    >&2 echo "Warning : cannot find compiler at path ${compiler}. Only checking C reference against python reference."
    have_compiler=1
fi

#check if test case DIRECTORY exists or not
if [ ! -d "$TESTDIRECTORY" ]; then
  # Control will enter here if $DIRECTORY doesn't exist.
  echo "Test case directory does not exist"
  exit
fi

if [ ! -d "$TESTDRIVER" ]; then
  # Control will enter here if $DIRECTORY doesn't exist.
  echo "Test driver directory does not exist"
  exit
fi

for i in ${TESTDIRECTORY}/*.c; do
  base=$(basename $i)
  #Run compiler on test case
  ${compiler} -S $i -o ${OUTPUT}/${base}.s
  #GCC assemble .s to object file
  ${MIPSFLAG} -o ${OUTPUT}/${base}.o -c ${OUTPUT}/${base}.s
  #Link object file with test driver using gcc MIPS FLAG on
  ${MIPSFLAG} -static -o ${EXEC}/${base} ${OUTPUT}/${base}.o ${TESTDRIVER}/${base}.c
  #Run execuable on QEMU virtual
  qemu-mips ${EXEC}/${base}
  RETURNCODE=$?
  #Check return code
  if [[${RETURNCODE} -eq 0]];then
    let "PASS++"
    echo "PASS TEST ${base}.c"
  fi
  let "COUNT++"
done

FAIL=${COUNT}-${PASS}
echo "Exit test suite with ${PASS} test case passed"
echo "*****************************"
echo " "
exit ${FAIL}
