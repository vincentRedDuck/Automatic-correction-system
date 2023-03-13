#!/bin/bash
#--------------- need to rewrite ---------------------
LAB_NAME='lab12'
EXERCISE_NAME='ex12'
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
	rm ${STU_ANS}
	exit 1
fi

STUDENT_EXE_FILE="${EXERCISE_NAME}-${EXERCISE_NUM}"

INPUT_FILE_1="${TA_DIRPATH}/${LAB_NAME}/demoEXE/ex12-2_testcase1.txt"
INPUT_FILE_2="${TA_DIRPATH}/${LAB_NAME}/demoEXE/ex12-2_testcase2.txt"
INPUT_FILE_3="${TA_DIRPATH}/${LAB_NAME}/demoEXE/ex12-2_testcase3.txt"

${EXE_PATH} ${INPUT_FILE_1} > ${TRUE_ANS}
./${STUDENT_EXE_FILE} ${INPUT_FILE_1} > ${STU_ANS}

${EXE_PATH} ${INPUT_FILE_2} > ${TRUE_ANS}
./${STUDENT_EXE_FILE} ${INPUT_FILE_2} > ${STU_ANS}

${EXE_PATH} ${INPUT_FILE_3} > ${TRUE_ANS}
./${STUDENT_EXE_FILE} ${INPUT_FILE_3} > ${STU_ANS}

#---------------------end--------------------------------

