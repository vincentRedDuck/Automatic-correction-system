#!/bin/bash
#--------------- need to rewrite ---------------------
LAB_NAME='lab10'
EXERCISE_NAME='ex10'
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

BOOK_IN="${TA_DIRPATH}/${LAB_NAME}/demoEXE/Pokedex.in"
TRUE_BOOK_OUT="${TA_DIRPATH}/${LAB_NAME}/demoEXE/Pokedex.out"
POKEMON_IN="${TA_DIRPATH}/${LAB_NAME}/demoEXE/t1"
TRUE_POKEMON_OUTPUT="${TA_DIRPATH}/${LAB_NAME}/demoEXE/t.out"
# EXTEST2="${TA_DIRPATH}/${LAB_NAME}/demoEXE/ex9-2-2.in"
# EXTEST3="${TA_DIRPATH}/${LAB_NAME}/demoEXE/ex9-2-3.in"

BOOK_OUT='tmp'
POKEMON_OUTPUT='P.out'

${EXE_PATH} ${BOOK_IN} ${TRUE_BOOK_OUT} ${POKEMON_IN} ${TRUE_POKEMON_OUTPUT}
./${INPUT_PATH} ${BOOK_IN} ${BOOK_OUT} ${POKEMON_IN} ${POKEMON_OUTPUT}

cat ${TRUE_BOOK_OUT} > ${TRUE_ANS}
cat ${BOOK_OUT} > ${STU_ANS}

cat ${TRUE_POKEMON_OUTPUT} >> ${TRUE_ANS}
cat ${POKEMON_OUTPUT} >> ${STU_ANS}

POKEMON_IN="${TA_DIRPATH}/${LAB_NAME}/demoEXE/t2"
${EXE_PATH} ${BOOK_IN} ${TRUE_BOOK_OUT} ${POKEMON_IN} ${TRUE_POKEMON_OUTPUT}
./${INPUT_PATH} ${BOOK_IN} ${BOOK_OUT} ${POKEMON_IN} ${POKEMON_OUTPUT}

cat ${TRUE_POKEMON_OUTPUT} >> ${TRUE_ANS}
cat ${POKEMON_OUTPUT} >> ${STU_ANS}

POKEMON_IN="${TA_DIRPATH}/${LAB_NAME}/demoEXE/t3"
${EXE_PATH} ${BOOK_IN} ${TRUE_BOOK_OUT} ${POKEMON_IN} ${TRUE_POKEMON_OUTPUT}
./${INPUT_PATH} ${BOOK_IN} ${BOOK_OUT} ${POKEMON_IN} ${POKEMON_OUTPUT}

cat ${TRUE_POKEMON_OUTPUT} >> ${TRUE_ANS}
cat ${POKEMON_OUTPUT} >> ${STU_ANS}

POKEMON_IN="${TA_DIRPATH}/${LAB_NAME}/demoEXE/t4"
${EXE_PATH} ${BOOK_IN} ${TRUE_BOOK_OUT} ${POKEMON_IN} ${TRUE_POKEMON_OUTPUT}
./${INPUT_PATH} ${BOOK_IN} ${BOOK_OUT} ${POKEMON_IN} ${POKEMON_OUTPUT}

cat ${TRUE_POKEMON_OUTPUT} >> ${TRUE_ANS}
cat ${POKEMON_OUTPUT} >> ${STU_ANS}

POKEMON_IN="${TA_DIRPATH}/${LAB_NAME}/demoEXE/t5"
${EXE_PATH} ${BOOK_IN} ${TRUE_BOOK_OUT} ${POKEMON_IN} ${TRUE_POKEMON_OUTPUT}
./${INPUT_PATH} ${BOOK_IN} ${BOOK_OUT} ${POKEMON_IN} ${POKEMON_OUTPUT}

cat ${TRUE_POKEMON_OUTPUT} >> ${TRUE_ANS}
cat ${POKEMON_OUTPUT} >> ${STU_ANS}

 rm ${POKEMON_OUTPUT} ${BOOK_OUT} ${TRUE_POKEMON_OUTPUT} ${TRUE_BOOK_OUT}
#---------------------end--------------------------------
