#!/bin/bash

DIR=$PWD
STU_CODE=$1
STORE_DIR='/tmp/final_2021/p05/'
TMP_DIR=$( mktemp -d -p /tmp final_sys.XXXX )
STU_ANS=${TMP_DIR}/stu.out

if [ ! -f ${STU_CODE} ]; then
    echo "No input file!"
    exit 0
fi

g++ ${STU_CODE} -o ${TMP_DIR}/p05
if [ ! -f ${TMP_DIR}/p05 ]; then
    echo "compile error"
    exit 0
fi

cd ${TMP_DIR}
cp ${STORE_DIR}testcase.in .
cp ${STORE_DIR}demoFinal5.py .

${TMP_DIR}/p05 testcase.in testcase.out
cat testcase.out > ${STU_ANS}

python3 demoFinal.py testcase.in ${STU_ANS}

if [ $? -eq 0 ]; then
    echo "Your answer is Correct"
else
    echo "Your answer is Wrong"
fi

