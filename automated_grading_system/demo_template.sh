#--------------- need to rewrite ---------------------
LAB_NAME='lab12'
EXERCISE_NUM='1'
TA_DIRPATH='/home/studemo/'
SHARE_PATH='/home/share/'
#------------------  end  ----------------------------

DEMO_PATH="${TA_DIRPATH}${LAB_NAME}/cpp/demoCode/demo_${LAB_NAME}-${EXERCISE_NUM}.cpp"
SHARE_PATH="${SHARE_PATH}${LAB_NAME}/demo_${LAB_NAME}-${EXERCISE_NUM}"

#---------- compile and authorize to the file --------
g++ ${DEMO_PATH} -o ${SHARE_PATH}
sudo chown root ${SHARE_PATH}
sudo chmod u+s ${SHARE_PATH}

