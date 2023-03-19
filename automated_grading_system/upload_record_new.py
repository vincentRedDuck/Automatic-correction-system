'''
$python3 upload_record.py "arg1" "arg2" "arg3"

arg1 : lab number. For example, if you want to update lab3, the arg1 is lab3.
arg2 : score
arg3 : exercise number
'''

import os
import re
import gspread
import sys
import time

from oauth2client.service_account import ServiceAccountCredentials
from os import listdir


TAcount = [ "demo", "123456789", "TA_shangming"] 

def diff(list1, list2) :
    return (list(list(set(list1) - set(list2) ) + list(set(list2) - set(list1) ) ) )

def write_unique_lines(path):
    with open(path,'r+') as f:
        uniqlines = set(f.readlines())
        #print(uniqlines)
        f.truncate(0)
    with open(path,'w') as f:
        f.writelines(set(uniqlines))


#---------open the google sheet---------

# auth 
auth_json_path = '/home/studemo/icp2021.json'
gss_scopes = ['https://spreadsheets.google.com/feeds']
credentials = ServiceAccountCredentials.from_json_keyfile_name(auth_json_path,gss_scopes)
gss_client = gspread.authorize(credentials)
spreadsheet_key = '1ozTlLaaujOJQSDouh23WzZyC_6Z-NM9hsvEnfhetzfw'
# get sheet
sheet = gss_client.open_by_key(spreadsheet_key)

# get worksheet by different name
lab = sheet.worksheet("Lab")

#------- end -----------

#--------- handle input data------------
'''

log files store in /home/stu0800000/lab#/log directory.
There are only one number in log file's name. For example, if you update exercise 1, the log file is ex1 or test1....
The code will catch "stu" keyboard in log file and then update the student score.

'''

labTitle = sys.argv[1]
score = sys.argv[2]
exerciseNumber = sys.argv[3]

#print("%s is Updating." %(labTitle))
labDir = "/home/studemo" + "/"  + labTitle + "/log/"
okDir = "/home/studemo" + "/" + labTitle + "/okLog/"
#print("The command \"pwd\" is %s" %(labDir))

files = listdir(labDir)
labNumber = re.search(r'\d+', labTitle).group()

stuSheet = []

for _ in range(1):
 
    nowFile = exerciseNumber +'.log'
    # print(nowFile,'\n')
    # exerciseNumber = re.search(r'\d+', nowFile).group()
    f = open(labDir + nowFile, 'r')
    studentDict = dict() 
    #------- filter repeating studentID --------------- 
    for line in f.readlines():
        items = line.split("\n", 1)
        # the studnet ID must "stu + ID".
        if items[0].strip()[0:3] != "stu":
            continue
        studentDict[items[0].strip()[3:]] = 1

    #------ test dictionary ----------- 
    #for key, value in studentDict.items():
    #    print("%s" %(key))
    #------- end test ----------------
    
    studentAllArray = []
    for key in studentDict :
        studentAllArray.append(key)
    studentAllArray.sort()

    f.close()
    #---------- end filter --------------------


    #------ get all iterms in okLog and convert them to list-------
    #!!permision deny
    if not os.path.exists(okDir + nowFile):
        os.mknod(okDir + nowFile)
    
    f = open(okDir + nowFile, 'r')
    
    write_unique_lines(okDir+exerciseNumber+'.log') # delete same students
    write_unique_lines(labDir+exerciseNumber+'.log') # delete same students
    
    studentOKArray = []
    for line in f.readlines() :
        stuID = line.split("\n", 1)
        studentOKArray.append(stuID[0]) 

    studentOKArray.sort()
    f.close()
    #------------ end get all items --------------

    #------ get items which need to update---------
    
    studentUpdateArray = studentAllArray # It can be compared after check the cell is empty or not
    studentUpdateArray = diff(studentAllArray, studentOKArray)
    # print(studentUpdateArray, studentAllArray, studentOKArray)
    #---------- end get updating items  -----------
    



    #------ write data to google sheet -----
    #find LAB # position. (In order to get base column location)

    lab_number = 'LAB'+'{:02}'.format(int(labNumber))
    leftPos = lab.find(lab_number)
    # according exercise # to shift base column location.
    # print('lab_number for test', lab_number, exerciseNumber)
    
    targetCol = leftPos.col + int(exerciseNumber) - 1 
    f = open(okDir + nowFile, "a+")
  

    stuSheet = lab.col_values(3)
    
    for value in studentUpdateArray : 
        try :
            TAcount.index(value)
            continue
        except :
            time.sleep(0.0000001)

            
        try :
            targetRow = stuSheet.index(value) + 1
            #print( stuSheet.index(value), targetRow)    
        except :
            #print("The student ID \"%s\" don't exist." %(value))
            stuSheet.append(value)
            targetRow = len(stuSheet)
            lab.update(chr(65 + 3 - 1) + str(targetRow), value)
        
        targetCell = lab.cell(str(targetRow), str(targetCol))
        # print('targetCell', targetCell, targetCell.value)

        if targetCell.value  is None : # when there is nothing in this cell 
            
            targetColStr = ""  
            lab.update_cell(targetCell.row, targetCell.col, score)
            #print("lab%s ex%s col:%s row:%s studentID:%s Score exists %s. No updates" %(labNumber, exerciseNumber, targetCol, targetRow, value, targetCell.value))
            pass               

        else :
            pass
            #print("lab%s ex%s col:%s row:%s studentID:%s Score exists %s. No updates" %(labNumber, exerciseNumber, targetCol, targetRow, value, targetCell.value))

        f.write("%s\n" %(value))     

        time.sleep(0.0000001)
    
    f.close()
    #------- end write -------------
    pass
