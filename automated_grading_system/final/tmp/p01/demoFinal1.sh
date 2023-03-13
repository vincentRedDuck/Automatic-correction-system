#!/bin/bash

DIR=$PWD
STU_CODE=$1
STORE_DIR='/tmp/final_2021/p01/'
TMP_DIR=$( mktemp -d -p /tmp final_sys.XXXX )
TRUE_FILE="${STORE_DIR}true.out"
ANS_FILE="${TMP_DIR}/ans.out"

if [ ! -f ${STU_CODE} ]; then
    echo "No input file!"
    exit 0
fi

g++ ${STU_CODE} -o ${TMP_DIR}/p01
if [ ! -f ${TMP_DIR}/p01 ]; then
    echo "compile error"
    exit 0
fi

cd ${TMP_DIR}
cp ${STORE_DIR}true.out .
cp ${STORE_DIR}testcase_*.in .
${TMP_DIR}/p01 testcase_19.in output 19
cat output > ${ANS_FILE}
${TMP_DIR}/p01 testcase_99.in output 99
cat output >> ${ANS_FILE}
${TMP_DIR}/p01 testcase_2668.in output 2668
cat output >> ${ANS_FILE}
${TMP_DIR}/p01 testcase_6466.in output 6466
cat output >> ${ANS_FILE}
${TMP_DIR}/p01 testcase_8705.in output 8705
cat output >> ${ANS_FILE}

diff -B -Z true.out $ANS_FILE
if [ $? -eq 0 ]; then
    echo "Your answer is Correct"
else
    echo "Your answer is Wrong"
fi

cd ..
#echo ${TMP_DIR}
rm -rf ${TMP_DIR}
