#!/bin/bash
#--------------- need to rewrite ---------------------
LAB_NAME='lab9'
EXERCISE_NAME='ex9'
EXERCISE_NUM='2'
TA_DIRPATH='/home/studemo'
CHECKRESULT_DIRPATH='/tmp'
#------------------  end  ----------------------------

EXE_PATH="${TA_DIRPATH}/${LAB_NAME}/demoEXE/${EXERCISE_NAME}-${EXERCISE_NUM}"
LOG_PATH="${TA_DIRPATH}/${LAB_NAME}/log/${EXERCISE_NUM}.log"
STU_CODE=$(find -name "${EXERCISE_NAME}-${EXERCISE_NUM}.cpp") #student exe name is same as Ta exe name.
STU_PATH="${CHECKRESULT_DIRPATH}/${LAB_NAME}/${USER}" #student exe name is same as Ta exe name.
TRUE_ANS="${CHECKRESULT_DIRPATH}/${LAB_NAME}/true${EXERCISE_NUM}"
STU_ANS="${CHECKRESULT_DIRPATH}/${LAB_NAME}/${LAB_NAME}-${USER}"

if [ ! -d "${CHECKRESULT_DIRPATH}/${LAB_NAME}" ]; then
    mkdir -p "${CHECKRESULT_DIRPATH}/${LAB_NAME}"
fi

if [ ! -f ${STU_CODE} ]; then
    echo "Can't find the file."
fi

#----need to rewrite(create stu ans and real ans)--------
g++ ${STU_CODE} -o ${EXERCISE_NAME}-${EXERCISE_NUM}
if [ $? -ne 0 ];then
	echo "Fail to compile"
	exit 0
fi

INPUT_PATH="${EXERCISE_NAME}-${EXERCISE_NUM}"

EXTEST1="${TA_DIRPATH}/${LAB_NAME}/demoEXE/ex9-2-1.in"
EXTEST2="${TA_DIRPATH}/${LAB_NAME}/demoEXE/ex9-2-2.in"
EXTEST3="${TA_DIRPATH}/${LAB_NAME}/demoEXE/ex9-2-3.in"

TEST="${CHECKRESULT_DIRPATH}/${LAB_NAME}/ex9-2.in"

TMP='tmp'
OUT='tt.in'
GOLDEN='out.golden'

cat ${EXTEST1} > ${TEST}
${EXE_PATH} 1 ${TEST} ${GOLDEN}
./${INPUT_PATH} 1 ${TEST} ${OUT}

cat ${GOLDEN} > ${TRUE_ANS}
cat ${OUT} > ${STU_ANS}

cat ${EXTEST2} > ${TEST}
${EXE_PATH} 2 ${TEST} ${GOLDEN}
./${INPUT_PATH} 2 ${TEST} ${OUT}

cat ${GOLDEN} >> ${TRUE_ANS}
cat ${OUT} >> ${STU_ANS}

cat ${EXTEST3} > ${OUT}
cat ${EXTEST3} > ${TEST}

${EXE_PATH} 1 ${TEST}
./${INPUT_PATH} 1 ${OUT}


# echo "${TEST3}.out"
# cat "${TEST3}.out"
cat "${TEST}.out" >> ${TRUE_ANS}

# echo "${OUT}.out"
# cat "${OUT}.out"

cat "${OUT}.out" >> ${STU_ANS}

rm ${OUT} ${GOLDEN} "${OUT}.out" ${TEST} "${TEST}.out"
#---------------------end--------------------------------
