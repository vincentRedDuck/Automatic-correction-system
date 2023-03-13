#!/bin/bash
#--------------- need to rewrite ---------------------
LAB_NAME='lab2'
EXERCISE_NAME='ex2'
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


#----need to rewrite(create stu ans and real ans)--------
g++ ${STU_CODE} -o ${EXERCISE_NAME}-${EXERCISE_NUM}
if [ $? -ne 0 ];then
	echo "Fail to compile"
	exit 1
fi
INPUT_PATH="${EXERCISE_NAME}-${EXERCISE_NUM}"
TMP='tmp'

echo 123.7654321 > ${TMP}
${EXE_PATH} < ${TMP} > ${TRUE_ANS}
./${INPUT_PATH} < ${TMP} > ${STU_ANS}

echo -0.0002345 > ${TMP}
${EXE_PATH} < ${TMP} >> ${TRUE_ANS}
./${INPUT_PATH} < ${TMP} >> ${STU_ANS}

echo 0.123456789 > ${TMP}
${EXE_PATH} < ${TMP} >> ${TRUE_ANS}
./${INPUT_PATH} < ${TMP} >> ${STU_ANS}

echo 9.98534293 > ${TMP}
${EXE_PATH} < ${TMP} >> ${TRUE_ANS}
./${INPUT_PATH} < ${TMP} >> ${STU_ANS}

echo -70593.33334 > ${TMP}
${EXE_PATH} < ${TMP} >> ${TRUE_ANS}
./${INPUT_PATH} < ${TMP} >> ${STU_ANS}

echo 0.0000567 > ${TMP}
${EXE_PATH} < ${TMP} >> ${TRUE_ANS}
./${INPUT_PATH} < ${TMP} >> ${STU_ANS}


rm ${TMP}

#---------------------end--------------------------------
