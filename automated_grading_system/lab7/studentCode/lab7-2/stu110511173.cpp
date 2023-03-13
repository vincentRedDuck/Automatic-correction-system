#include <iostream>
using namespace std;

void encode(char [],int);
void decode(char [],int);

int main()
{
    int sel,n;
    cout << "1: encoder 2: decoder 3: quit: ";
    //cin >> sel;
    //cout << "Please enter sentences length: ";
    //cin >> n;
    while(cin >> sel)
    {
        char A[100];
        if(sel==3)
            break;
        else if( sel!=1 && sel!=2)
        {
            cout << "invalid input" << endl;
            
        }   
        else if(sel==1)
        {
            cout << "Please enter sentences length: ";
            cin >> n;
            for(int i = 0; i<n ; i++)
            {
                cin >> A[i];
            }
            encode(A,n);
        }
        else if(sel == 2)
        {
            cout << "Please enter sentences length: ";
            cin >> n;

            for(int i = 0 ; i<n ; i++)
            {
                cin >> A[i];
            }
            decode(A,n);
        }
        

        cout << "1: encoder 2: decoder 3: quit: ";
        //cin >> sel;
        //cout << "Please enter sentences length: ";
        //cin >> n;

    }
    return 0;
}

void encode(char vec[],int a)
{
    char A[100];
    char B[100];
    int x=0;
    int y=0;
    for(int i = 0 ; i<a ; i++)
    {
        if(i%2==0)
        {
            A[x] = vec[i];
            x++;
        }
        else
        {
            B[y] = vec[i];
            y++;
        }
    }
    for(int i = 0 ; i<x ; i++ )
    {
        cout << A[i];
    }
    for(int i = 0 ; i<y ; i++)
    {
        cout << B[i];
    }
    cout << endl << endl;
}

void decode(char vec[],int a)
{
    char A[100];
    char B[100];
    int x=0;
    int y=0;
    for(int i = 0; i < a ; i++)
    {
        if(i<a/2)
        {
            A[x] = vec[i];
            x++;
        }
        else
        {
            B[y] = vec[i];
            y++;
        }
    }
    if(x==y)
    {
        for(int i = 0; i<x ; i++ )
        {
            cout << A[i] << B[i] ;
        }    
        cout << endl << endl;
    }
    else
    {
        for(int i = 0; i<x ; i++ )
        {
            if(i==(x-1))
                cout << A[i];
            else
                cout << A[i] << B[i] ;
        }
        cout << endl << endl;
    }

}

