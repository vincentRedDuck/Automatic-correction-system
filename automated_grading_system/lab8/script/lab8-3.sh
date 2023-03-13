#!/bin/bash
#--------------- need to rewrite ---------------------
LAB_NAME='lab8'
EXERCISE_NAME='ex8'
EXERCISE_NUM='3'
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
TMP='tmp'

echo "13579" > ${TMP}
echo "mouse++hates--cat" >> ${TMP}
echo "hard fucking//be**will+++Exam&&Final" >> ${TMP}
echo "hello  ((*% world//95 " >> ${TMP}
echo "Stop the program" >> ${TMP}
${EXE_PATH} < ${TMP} > ${TRUE_ANS}
./${INPUT_PATH} < ${TMP} > ${STU_ANS}

${EXE_PATH} < ${TMP} > ${TRUE_ANS}
./${INPUT_PATH} < ${TMP} > ${STU_ANS}

${EXE_PATH} < ${TMP} > ${TRUE_ANS}
./${INPUT_PATH} < ${TMP} > ${STU_ANS}


rm ${TMP}
#---------------------end--------------------------------
