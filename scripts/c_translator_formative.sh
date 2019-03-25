#!/bin/bash

if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="bin/c_compiler"
fi

have_compiler=0
if [[ ! -f bin/c_compiler ]] ; then
    >&2 echo "Warning : cannot find compiler at path ${compiler}. Only checking C reference against python reference."
    have_compiler=1
fi

input_dir="test/c_translator/formative"
testcase="tmp/formative/testcase"
objectfile="tmp/formative/C_output"
workingpython="tmp/formative/python"

rm -r ${testcase}
mkdir -p ${testcase}
cp -r ${input_dir} ${testcase}
mkdir -p ${workingpython}
mkdir -p ${objectfile}

PASSED=0
CHECKED=0

for i in ${input_dir}/*.c ; do
    base=$(echo $i | sed -E -e "s|${input_dir}/([^.]+)[.]c|\1|g");

    # Compile the reference C version
    gcc $i -o $objectfile/$base

    # Run the reference C version
    $objectfile/$base
    REF_C_OUT=$?

    # Run the reference python version
    python3 ${input_dir}/$base.py
    REF_P_OUT=$?

    if [[ ${have_compiler} -eq 0 ]] ; then

        # Create the DUT python version by invoking the compiler with translation flags
        $compiler --translate $i -o ${workingpython}/$base-got.py

        # Run the DUT python version
        python ${workingpython}/$base-got.py
        GOT_P_OUT=$?
    fi

    # if [[ $REF_C_OUT -ne $REF_P_OUT ]] ; then
    #   #echo "$base, REF_FAIL, Expected ${REF_C_OUT}, got ${REF_P_OUT}"
    # elif [[ ${have_compiler} -ne 0 ]] ; then
    #     echo "$base, Fail, No C compiler/translator"
    if [[ $REF_C_OUT -ne $GOT_P_OUT ]] ; then
        echo "$base, Fail, Expected ${REF_C_OUT}, got ${GOT_P_OUT}"
    else
        echo "$base, Pass"
        PASSED=$(( ${PASSED}+1 ))
    fi
    CHECKED=$(( ${CHECKED}+1 ));
done

exit $((${CHECKED}-${PASSED}))
