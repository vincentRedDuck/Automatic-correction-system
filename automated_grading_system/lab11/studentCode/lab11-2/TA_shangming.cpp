#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

struct element_s
{
    int data;
    element_s *ptr;
};

fstream *open_fstream(string FilePath);
void close_fstream(fstream *fp);
element_s *create_element(string number);
bool check_number_in_linked_list(element_s *headPtr, int number);

int main(int argc, char *argv[])
{
    fstream *fp;
    element_s *headPtr;

    fp = open_fstream(argv[1]);

    //========================= student code ========================
    /* This part is consisted that:
        1. create a linked list
        2. read the file and then update elements of the linked list
    */
    string strNum;
    element_s *lastPtr;
    bool isFirst = true;

    while (getline(*fp, strNum, ','))
    {
        if (isFirst)
        {
            headPtr = create_element(strNum);
            lastPtr = headPtr;
            isFirst = false;
        }
        else
        {
            lastPtr->ptr = create_element(strNum);
            lastPtr = lastPtr->ptr;
        }
    }

    //====================== student code end =========================

    int userInputNumber;
    while (cin >> userInputNumber && (userInputNumber >= 0))
        cout << "Find? " << ((check_number_in_linked_list(headPtr, userInputNumber)) ? "Yes" : "No") << endl;

    close_fstream(fp);
    return 0;
}

fstream *open_fstream(string FilePath)
{
    //========================= student code ========================
    fstream *fp;
    fp = new fstream;
    fp->open(FilePath, ios::in);
    return fp;
    //====================== student code end =========================
}

void close_fstream(fstream *fp)
{
    //========================= student code ========================
    fp->close();
    //====================== student code end =========================
}

element_s *create_element(string number)
{
    //========================= student code ========================
    element_s *new_element;
    new_element = new element_s;
    new_element->data = stoi(number);
    new_element->ptr = NULL;
    return new_element;
    //====================== student code end =========================
}

bool check_number_in_linked_list(element_s *headPtr, int number)
{
    //========================= student code ========================
    element_s *nowPtr = headPtr;
    while (nowPtr != NULL)
    {
        if (nowPtr->data == number)
            return true;
        nowPtr = nowPtr->ptr;
    }
    return false;
    //====================== student code end =========================
}