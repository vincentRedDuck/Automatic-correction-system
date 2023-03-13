#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

struct element_s
{
    int data;
    struct element_s *ptr;
};

fstream* open_fstream(string FilePath);
void close_fstream(fstream *fp);
struct element_s* create_element(string number);
bool check_number_in_linked_list(struct element_s *headPtr, int number);

int main(int argc, char *argv[])
{
    fstream *fp;
    struct element_s *headPtr;    

    fp = open_fstream(argv[1]);

    //============= student code =================
    // read each number from the file and then update elements of the linked list
    string strNum;
    struct element_s *lastPtr;
    bool isFirst = true;

    while (getline(*fp, strNum, ',')) {
        if (isFirst) {
            headPtr = create_element(strNum);
            lastPtr = headPtr;
            isFirst = false;            
        } else {        
            lastPtr->ptr = create_element(strNum);            
            lastPtr = lastPtr->ptr;   
        }        
    }    
   //============ student code end ===============    
   //
    int userInputNumber;
    while (cin >> userInputNumber && (userInputNumber >= 0)) 
        cout << "Find? " << ((check_number_in_linked_list(headPtr, userInputNumber))?"Yes" : "No") << endl;

    close_fstream(fp);
    return 0;
}

fstream* open_fstream(string FilePath)
{
    //============= student code =================
    //you need create fstream object and then open the file
    fstream *fp;
    fp = new fstream;
    fp->open(FilePath, ios::in);

    return fp;
   //============ student code end ===============    

}

void close_fstream(fstream *fp)
{
    //============= student code =================
    fp->close();
   //============ student code end ===============    
}

struct element_s* create_element(string number)
{
   //============= student code =================
    struct element_s *newElement;
    newElement = new struct element_s;
    newElement->data = stoi(number);
    newElement->ptr = NULL;

    return newElement;
   //============ student code end ===============    
}

bool check_number_in_linked_list(struct element_s *headPtr, int number)
{   
    //============= student code =================
    struct element_s *nowPtr = headPtr;
    while(nowPtr != NULL) {
        if (nowPtr->data == number)
            return true;
        nowPtr = nowPtr->ptr;
    }
    return false;
    //=========== student code end ===============
}
