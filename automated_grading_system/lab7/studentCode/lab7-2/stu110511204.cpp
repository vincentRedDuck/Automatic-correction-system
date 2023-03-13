#include <iostream>
using namespace std;

const int MAX_LENGTH = 100;

int main()
{
    do
    {
        int choose;
        cout << "1: encoder 2: decoder 3: quit : ";
        cin >> choose;

        if(choose == 1)
        {
            int sentenceLength = 0;
            char sentences[MAX_LENGTH];
            char sentences1[MAX_LENGTH] = "";
            char sentences2[MAX_LENGTH] = "";

            cout<<"Please enter sentences length: ";
            cin>>sentenceLength;

            for(int i =0; i<sentenceLength; i++)
                cin>>sentences[i];
            for(int i =0, j=0; i<sentenceLength/2; i++,j++)
                sentences1[j] = sentences[i*2];
            for(int i =1, j = 0; i<=sentenceLength/2; i++, j++)
                sentences2[j] = sentences[i*2-1];

            //for odd length
            if(sentenceLength%2==1)
                sentences1[sentenceLength/2+1] = sentences[sentenceLength-1];

            for( int i =0; i<sentenceLength/2; i++)
                cout<<sentences1[i];
            //for odd length
            if(sentenceLength%2==1)
                cout<<sentences1[sentenceLength/2+1];
            for( int i =0; i<sentenceLength/2; i++)
                cout<<sentences2[i];
            cout<<endl<<endl;

        }

        else if(choose == 2)
        {
            int sentenceLength = 0;
            char sentences[MAX_LENGTH];
            char sentences1[MAX_LENGTH/2];
            char sentences2[MAX_LENGTH/2];

            cout<<"Please enter sentences length: ";
            cin>>sentenceLength;

            for(int i =0; i<sentenceLength; i++)
                cin>>sentences[i];

            if(sentenceLength%2==0)
                for(int i =0; i<sentenceLength/2; i++)
                    cout<<sentences[i]<<sentences[sentenceLength/2+i];
            else//for old length
            {
                for(int i =0; i<sentenceLength/2; i++)
                    cout<<sentences[i]<<sentences[sentenceLength/2+i+1];
                cout<<sentences[sentenceLength/2];
            }
            cout<<endl<<endl;
        }
        else if (choose == 3)
            break;
        else
            cout<<"invalid input"<<endl<<endl;
    } while (1);

    return 0;
}

