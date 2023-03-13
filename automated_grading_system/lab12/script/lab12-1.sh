#!/bin/bash
#--------------- need to rewrite ---------------------
LAB_NAME='lab12'
EXERCISE_NAME='ex12'
EXERCISE_NUM='1'
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
        rm ${STU_ANS}
        exit 1
fi

STUDENT_EXE_FILE="${EXERCISE_NAME}-${EXERCISE_NUM}"

INPUT_FILE="${TA_DIRPATH}/${LAB_NAME}/demoEXE/ex12-1_testcase.txt"

${EXE_PATH} > ${TRUE_ANS} < ${INPUT_FILE}
./${STUDENT_EXE_FILE} > ${STU_ANS} < ${INPUT_FILE}
#---------------------end--------------------------------

