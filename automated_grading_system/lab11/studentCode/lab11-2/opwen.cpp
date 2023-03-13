#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct element_s {
    int data;
    element_s *ptr;
};

fstream* open_fstream(string FilePath);
void close_fstream(fstream *fp);
struct element_s* create_element(string number);
bool check_number_in_linked_list(element_s *headPtr, int number);

int main(int argc, char *argv[])
{
    fstream *fp;
    element_s *headPtr = NULL, *curr = headPtr;    

    fp = open_fstream(argv[1]);

    //========================= student code ========================
    // read the file and then update elements of the linked list
    string tok;
    while (getline(*fp, tok, ',')) {
      if (curr==NULL) {
        headPtr = curr = create_element(tok);
      } else {
        curr->ptr = create_element(tok);
        curr = curr->ptr;
      }
    } 
   //====================== student code end =========================    

    int userInputNumber;
    while (cin >> userInputNumber && (userInputNumber >= 0)) 
        cout << "Find? " << ((check_number_in_linked_list(headPtr, userInputNumber)) ? "Yes" : "No") << endl;

    close_fstream(fp);
    return 0;
}

fstream* open_fstream(string FilePath) {
    //========================= student code ========================
  fstream *fin = new fstream(FilePath.c_str(), ios::in);
  return fin;
    //====================== student code end ========================= 
}

void close_fstream(fstream *fp) {
    //========================= student code ==========================
  fp->close(); delete fp; fp = NULL;
    //====================== student code end ========================= 
}

element_s* create_element(string number) {
    //========================= student code ========================
  element_s *x = new element_s({atoi(number.c_str()),NULL});
  return x;  
    //====================== student code end ========================= 
}

bool check_number_in_linked_list(element_s *headPtr, int number) {    
    //========================= student code ========================
  element_s *curr = headPtr;
  while (curr!=NULL) {
    if (curr->data == number) return true;
    curr = curr->ptr;
  }
  return false;
    //====================== student code end ========================= 
}
