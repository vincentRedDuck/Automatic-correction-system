#include<iostream>
using namespace std;

void encode()
{
    int length;
    cout<<"Please enter sentences length: ";
    cin>>length;
    char arr[length];
    for(int i=0;i<length;i++)
    {cin>>arr[i];}
    for(int i=0;i<length;i+=2)
    {cout<<arr[i];}
    for(int i=1;i<length;i+=2)
    {cout<<arr[i];}
    cout<<endl<<endl;
}

void decode()
{
    int length;
    cout<<"Please enter sentences length: ";
    cin>>length;
    char arr[length];
    for(int i=0;i<length;i++)
    {cin>>arr[i];}
    for(int i=0;i<length/2;i++)
    {
        for(int j=i;j<length;j+=length/2)
        cout<<arr[j];

    }
    cout<<endl<<endl;
}

int main()
{
    while(1)
    {
        int input;
        cout<<"1: encoder 2: decoder 3: quit: ";
        cin>>input;
        switch(input)
        {
            case 1:
            encode();
            break;
            case 2:
            decode();
            break;
            case 3:
            return 0;
            default:
            cout<<"invalid input"<<endl<<endl;
        }
    }

}
