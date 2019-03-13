#!/bin/bash
MIPSFLAG="-march=mips1"
TESTDIRECTORY="test/c_test"
TESTDRIVER="test/c_driver_test"
OUTPUT="test/C_output"
mkdir -p ${OUTPUT}

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

for i in ${TESTDRIVER}/*.c ; do
    #What does this line do ???
    base=$(echo $i | sed -E -e "s|${TESTDRIVER}/([^.]+)[.]c|\1|g");
    # Compile driver file into MIPS object
    gcc $i ${MIPSFLAG} -o $OUTPUT/$base
done

for i in ${TESTDIRECTORY}/*.c; do
  base=$(echo $i | sed -E -e "s|${TESTDIRECTORY}/([^.]+)[.]c|\1|g");
  #Run compiler on test case
  ${compiler} -S $i -o ${OUTPUT}/$base.s
  gcc $OUTPUT/$base.o $OUTPUT/$base.s
done


echo "Exit test suite without erros"
echo "*****************************"
echo " "
