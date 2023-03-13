#!/bin/bash
#--------------- need to rewrite ---------------------
LAB_NAME='lab1'
EXERCISE_NAME='ex1'
EXERCISE_NUM='1'
TA_DIRPATH='/home/studemo'
CHECKRESULT_DIRPATH='/tmp'
#------------------  end  ----------------------------

EXE_PATH="${TA_DIRPATH}/${LAB_NAME}/demoEXE/${EXERCISE_NAME}-${EXERCISE_NUM}"
LOG_PATH="${TA_DIRPATH}/${LAB_NAME}/log/${EXERCISE_NUM}.log"
STU_PATH="${CHECKRESULT_DIRPATH}/${LAB_NAME}/${USER}" #student exe name is same as Ta exe name.
TRUE_ANS="${CHECKRESULT_DIRPATH}/${LAB_NAME}/true${EXERCISE_NUM}"
STU_CODE=$(find -name "${EXERCISE_NAME}-${EXERCISE_NUM}.cpp") #student exe name is same as Ta exe name.
STU_ANS="${CHECKRESULT_DIRPATH}/${LAB_NAME}/${LAB_NAME}-${USER}"
DEMO_INPUT_FILE="${TA_DIRPATH}/${LAB_NAME}/testcase/${LAB_NAME}-${EXERCISE_NUM}.txt"

STU_TXT=$(find -name "${EXERCISE_NAME}-${EXERCISE_NUM}.txt")
TRUE_TXT="${TA_DIRPATH}/${LAB_NAME}/demoEXE/${EXERCISE_NAME}-${EXERCISE_NUM}.txt"

if [ ! -d "${CHECKRESULT_DIRPATH}/${LAB_NAME}" ]; then
    mkdir -p "${CHECKRESULT_DIRPATH}/${LAB_NAME}"
fi

if [ ! -f ${STU_CODE} ]; then
    echo "Can't find the file."
fi

#----need to rewrite(create stu ans and real ans)--------


# output true ans and student's ans
cat ${TRUE_TXT} > ${TRUE_ANS}
cat ${STU_TXT} > ${STU_ANS}
#---------------------end--------------------------------
