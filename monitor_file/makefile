SHARE_LIB = logger.so
SHARE_LIB_CPP = hw2.cpp
EXE_FILE = logger
EXE_FILE_CPP = logger.cpp

#---------------------------------------------------

all:	
	g++ -fPIC -shared -o $(SHARE_LIB) $(SHARE_LIB_CPP) -ldl
	g++ -o $(EXE_FILE) $(EXE_FILE_CPP)

clean:
	rm -f ${EXE_FILE} ${SHARE_LIB}