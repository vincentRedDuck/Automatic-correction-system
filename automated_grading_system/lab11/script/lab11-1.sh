#!/bin/bash
#--------------- need to rewrite ---------------------
LAB_NAME='lab11'
EXERCISE_NAME='ex11'
EXERCISE_NUM='1'
TA_DIRPATH='/home/studemo'
CHECKRESULT_DIRPATH='/tmp'
#------------------  end  ----------------------------

EXE_PATH="${TA_DIRPATH}/${LAB_NAME}/demoEXE/${EXERCISE_NAME}-${EXERCISE_NUM}"
LOG_PATH="${TA_DIRPATH}/${LAB_NAME}/log/${EXERCISE_NUM}.log"
STU_CODE=$(find -name "${EXERCISE_NAME}-${EXERCISE_NUM}.h") #student exe name is same as Ta exe name.
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
STU_TMP_DIR="${CHECKRESULT_DIRPATH}/${LAB_NAME}/${USER}_dir"
if [ ! -d "${STU_TMP_DIR}" ]; then
    mkdir -p "${STU_TMP_DIR}"
fi

TA_MAIN_FUNC="/home/studemo/lab11/demoEXE/${EXERCISE_NAME}-${EXERCISE_NUM}.cpp"
cp ${TA_MAIN_FUNC} ${STU_TMP_DIR} 
cp ${STU_CODE} ${STU_TMP_DIR}


g++ -w "${STU_TMP_DIR}/${EXERCISE_NAME}-${EXERCISE_NUM}.cpp" -o "${STU_TMP_DIR}/${EXERCISE_NAME}-${EXERCISE_NUM}"
if [ $? -ne 0 ];then
        echo "Fail to compile"
        rm ${STU_ANS}
        exit 1
fi



STUDENT_EXE_FILE="${STU_TMP_DIR}/${EXERCISE_NAME}-${EXERCISE_NUM}"
INPUT_FILE="${TA_DIRPATH}/${LAB_NAME}/demoEXE/ex2-input1.txt"


${EXE_PATH} ${INPUT_FILE} > ${TRUE_ANS} 
${STUDENT_EXE_FILE} ${INPUT_FILE} > ${STU_ANS}
#---------------------end--------------------------------

