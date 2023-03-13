#!/bin/bash
#--------------- need to rewrite ---------------------
LAB_NAME='lab1'
EXERCISE_NAME='ex1'
EXERCISE_NUM='2'
TA_DIRPATH='/home/studemo'
CHECKRESULT_DIRPATH='/tmp'
#------------------  end  ----------------------------

EXE_PATH="${TA_DIRPATH}/${LAB_NAME}/demoEXE/${EXERCISE_NAME}-${EXERCISE_NUM}"
LOG_PATH="${TA_DIRPATH}/${LAB_NAME}/log/${EXERCISE_NUM}.log"
STU_CODE=$(find -name "${EXERCISE_NAME}-${EXERCISE_NUM}_demo.zip") #student exe name is same as Ta exe name.
STU_PATH="${CHECKRESULT_DIRPATH}/${LAB_NAME}/${USER}" #student exe name is same as Ta exe name.
TRUE_ANS="${CHECKRESULT_DIRPATH}/${LAB_NAME}/true${EXERCISE_NUM}"
STU_ANS="${CHECKRESULT_DIRPATH}/${LAB_NAME}/${LAB_NAME}-${USER}"
DEMO_INPUT_FILE="${TA_DIRPATH}/${LAB_NAME}/testcase/${LAB_NAME}-${EXERCISE_NUM}.txt"


if [ ! -d "${CHECKRESULT_DIRPATH}/${LAB_NAME}" ]; then
    mkdir -p "${CHECKRESULT_DIRPATH}/${LAB_NAME}"
fi


#----need to rewrite(create stu ans and real ans)--------

# compile student code
 if [ ! -d "${STU_PATH}/${EXERCISE_NAME}-${EXERCISE_NUM}" ]; then
    mkdir -p "${STU_PATH}/${EXERCISE_NAME}-${EXERCISE_NUM}"
else
    rm -rf "${STU_PATH}/${EXERCISE_NAME}-${EXERCISE_NUM}"
    mkdir -p "${STU_PATH}/${EXERCISE_NAME}-${EXERCISE_NUM}"
 fi


unzip ${STU_CODE} -d "${STU_PATH}/${EXERCISE_NAME}-${EXERCISE_NUM}"


# output true ans and student's ans
cd ${EXE_PATH}
tree > ${TRUE_ANS}
"${EXE_PATH}/result/answer.o" >> ${TRUE_ANS}

cd "${STU_PATH}/${EXERCISE_NAME}-${EXERCISE_NUM}"
tree > ${STU_ANS}
"${STU_PATH}/${EXERCISE_NAME}-${EXERCISE_NUM}/result/answer.o" >> ${STU_ANS}
# cat ${TRUE_ANS}
# cat ${STU_ANS}
#---------------------end--------------------------------
