#!/bin/bash
#--------------- need to rewrite ---------------------
LAB_NAME='lab0'
EXERCISE_NUM='1'
TA_DIRPATH='/home/studemo'
CHECKRESULT_DIRPATH='/tmp'
#------------------  end  ----------------------------

EXE_PATH="${TA_DIRPATH}/${LAB_NAME}/demoEXE/${LAB_NAME}-${EXERCISE_NUM}"
LOG_PATH="${TA_DIRPATH}/${LAB_NAME}/log/${EXERCISE_NUM}.log"
STU_CODE=$(find -name "${LAB_NAME}-${EXERCISE_NUM}.cpp") #student exe name is same as Ta exe name.
STU_PATH="${CHECKRESULT_DIRPATH}/${LAB_NAME}/${USER}" #student exe name is same as Ta exe name.
TRUE_ANS="${CHECKRESULT_DIRPATH}/${LAB_NAME}/true${EXERCISE_NUM}"
STU_ANS="${CHECKRESULT_DIRPATH}/${LAB_NAME}/${LAB_NAME}-${USER}"
DEMO_INPUT_FILE="${TA_DIRPATH}/${LAB_NAME}/testcase/${LAB_NAME}-${EXERCISE_NUM}.txt"


if [ ! -d "${CHECKRESULT_DIRPATH}/${LAB_NAME}" ]; then
    mkdir -p "${CHECKRESULT_DIRPATH}/${LAB_NAME}"
fi


#----need to rewrite(create stu ans and real ans)--------

# compile student code
g++ ${STU_CODE} -o ${STU_PATH}

# output true ans and student's ans
${EXE_PATH} > ${TRUE_ANS}
${STU_PATH} > ${STU_ANS}
#---------------------end--------------------------------
