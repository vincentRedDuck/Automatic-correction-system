#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct inf
{
    string stu;
    int sco1;
    int sco2;
    int sco3;
    double avg ;
};


int main(int argc, char *argv[])
{
    if(argc==3)
    {
        int n;
        string name = argv[2];
        ifstream inFile(argv[2]);
        inf A[100];
        inFile >> n;
        for(int i = 0; i<n ;i++)
        {
            inFile >> A[i].stu >> A[i].sco1 >> A[i].sco2 >> A[i].sco3;  
            A[i].avg = (A[i].sco1+A[i].sco2+A[i].sco3)/3.0;
        }
         
        /*for (int jdx = 1; jdx < n; jdx++) 
        {
            int key = A[jdx].avg;
            int idx = jdx - 1;
            while ( idx >= 0 && A[idx].avg > key) 
            {
                A[idx+1] = A[idx];
                --idx;
            }
            A[idx+1].avg = key;
        }*/
        if(stoi(argv[1])==1)
        {
        
            inf temp;
	        
	        for (int i=0;  i<n-1; i++)
            { 
                
		        for (int j=0; j<n-1-i; j++) 
		        {
			        if (A[j].avg > A[j+1].avg)
			        {
				        temp = A[j];
				        A[j] = A[j+1];
				        A[j+1] = temp;
			        }
                }   
            }
        }
        else if(stoi(argv[1])==2)
        {
            int i, j;
            inf temp;
	        for (i=0;  i<n-1; i++)
            { 
		        for (j=0; j<n-1-i; j++) 
		        {
			        /*for(int k = 0; k<100 ; k++)
                    {
                        if (A[j].stu[0] > A[j+1].stu[0])
			            {
				        temp = A[j];
				        A[j] = A[j+1];
				        A[j+1] = temp;
				        break;
			            }   
                        else if (A[j].stu[0] < A[j+1].stu[0])
                            break;
                    }*/
                    
                    if (A[j].stu > A[j+1].stu)
                    {
                        temp = A[j];
                        A[j] = A[j+1];
                        A[j+1] = temp;
                    }
                }
            }
        } 
        ofstream outFile(name+".out");
        
        for(int i = 0 ; i<n ; i++)
        {
            outFile <<  A[i].stu << " " << A[i].sco1 << " " << A[i].sco2
            << " " << A[i].sco3 << " " << fixed << setprecision(4) << A[i].avg << endl;
        }
        
    }
    else
    {
        int n;
        ifstream inFile(argv[2]);
        inf A[100];
        inFile >> n;
        for(int i = 0; i<n ;i++)
        {
            inFile >> A[i].stu >> A[i].sco1 >> A[i].sco2 >> A[i].sco3;  
            A[i].avg = (A[i].sco1+A[i].sco2+A[i].sco3)/3.0;
        }
        if(stoi(argv[1])==1)
        {
            int i, j;
            inf temp;
	        for (i=0;  i<n-1; i++)
            { 
		        for (j=0; j<n-1-i; j++) 
		        {
			        if (A[j].avg > A[j+1].avg)
			        {
				        temp = A[j];
				        A[j] = A[j+1];
				        A[j+1] = temp;
			        }
                }
            }

        }    
        else if(stoi(argv[1])==2)
        {
            int i, j;
            inf temp;
	        for (i=0;  i<n-1; i++)
            { 
		        for (j=0; j<n-1-i; j++) 
		        {
                    /*for(int k = 0; k<100 ; k++)
                    {
			            if (A[j].stu[0] > A[j+1].stu[0])
			            {
				            temp = A[j];
				            A[j] = A[j+1];
				            A[j+1] = temp;
                            break;
			            }
                        else if(A[j].stu[0] < A[j+1].stu[0])
                            break;

                    }*/
                     if (A[j].stu > A[j+1].stu)
                    {
                        temp = A[j];
                        A[j] = A[j+1];
                        A[j+1] = temp;
                    }

                }
            }     
        }
        /*int i, j;
        inf temp;
	    bool exchanged = true;
	    for (i=0; exchanged && i<n-1; i++)
        { 
            exchanged = false;
		    for (j=0; j<n-1-i; j++) 
		    {
			    if (A[j].stu[0] > A[j+1].stu[0])
			    {
				    temp = A[j];
				    A[j] = A[j+1];
				    A[j+1] = temp;
				    exchanged = true;
			    }
            }
        }*/
        ofstream outFile(argv[3]);
        for(int i = 0 ; i<n ; i++)
        {
            outFile <<  A[i].stu << " " << A[i].sco1 << " " << A[i].sco2
            << " " << A[i].sco3 << " " << fixed << setprecision(4) << A[i].avg << endl;

        }

        
    }
    return 0;
}
