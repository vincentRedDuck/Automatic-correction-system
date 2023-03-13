#include<iostream>
#include<string>
using namespace std;

int main()
{	int count=0;

	string sentence;
	cout<<"Enter message: "; getline(cin,sentence);
	while(sentence!="Stop"){
		for(int i=0;i<=26;i++){

			for(int j=0;j<sentence.length();j++){
			        
				if (sentence[j]==char(i+'A')){
						
                                 count++ ;

				 }				 
                       	} 
			if(count>0){
                          cout<<char(i+'A')<<": "<<count<<endl;
			  count=0;
                        }
		}
			for(int i=0;i<=26;i++){

                        for(int j=0;j<sentence.length();j++){

                                if (sentence[j]==char(i+'a')){

                                 count++ ;

                                 }
                        }
                        if(count>0){
                          cout<<char(i+'a')<<": "<<count<<endl;
                          count=0;
                        }

		}
			cout<<"Enter message: "; getline(cin,sentence);

       }	

return 0;
}

			


