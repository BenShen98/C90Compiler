#!/bin/bash
MIPSFLAG="mips-linux-gnu-gcc -mfp32"
MIPS_OBJCOPY="mips-linux-gnu-objcopy"
MIPS_OBJDUMP="mips-linux-gnu-objdump"
MIPS_CPPFLAGS="-W -Wall -O3 -fno-builtin -march=mips1 -mfp32"
MIPS_LDFLAGS="-nostdlib -Wl,-melf32btsmip -march=mips1 -nostartfiles -mno-check-zero-division -Wl,--gpsize=0 -static -Wl,-Bstatic -Wl,--build-id=none --entry=0000000010000000"
MIPS_LINKER=src/linker.ld
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
  base=${base%.c}
  #Run compiler on test case
  #${compiler} -S $i -o ${OUTPUT}/${base}.s
  ${MIPSFLAG} -S $i -o ${OUTPUT}/${base}.s
  #GCC assemble .s to object file
  ${MIPSFLAG} -c ${OUTPUT}/${base}.s -o ${OUTPUT}/${base}.o
  #Link object file with test driver using gcc MIPS FLAG on
  ${MIPSFLAG} -static -o ${EXEC}/${base} ${OUTPUT}/${base}.o ${TESTDRIVER}/${base}.c
  #Run execuable on QEMU virtual
  qemu-mips ${EXEC}/${base}
  RETURNCODE=$?
  #Check return code
  if [[ "$RETURNCODE" -eq "0" ]];then
    let "PASS++"
    echo "=>PASS TEST ${base}.c"
    printf "\n\n"
  fi
  let "COUNT++"
done

for i in ${OUTPUT}/*.s; do
  base=$(basename $i)
  base=${base%.s}
  mips-linux-gnu-gcc ${MIPS_CPPFLAGS} -c ${OUTPUT}/${base}.s -o ${DUMP}/${base}.o
  mips-linux-gnu-gcc ${MIPS_CPPFLAGS} ${MIPS_LDFLAGS} -T ${MIPS_LINKER} ${DUMP}/${base}.o -o ${DUMP}/${base}.elf
  ${MIPS_OBJDUMP} -j .text -D ${DUMP}/${base}.elf > ${DUMP}/${base}.mips.s

  echo "********************TEST ${base}.c********************"
  cat ${DUMP}/${base}.mips.s
  echo "********************END ${base}.c********************"
  printf "\n\n"

done

FAIL=$(( ${COUNT}-${PASS} ))
echo "Exit with ${PASS} test case passed"
echo "*********************************************************"
exit ${FAIL}
