#include <iostream>

using namespace std;

int main()
{

    while(1){
        int type;
        cout <<"1: encoder 2: decoder 3: quit: ";
        cin >>type;

        if(type == 3){  

            break;

        }
        else if(type >3){

            cout <<"invalid input";
            cout <<endl<<endl;
        }
        else{

            if(type==1){//encoder
                int enc_length;
                //int enc_char;
                cout <<"Please enter sentences length: ";
                cin >>enc_length;
                char enc_char[enc_length];
                
                for(int i = 0;i <enc_length;i++ ){
                    cin >>enc_char[i];
                }

                int enc_topnum;
                int odd ;
                if(enc_length%2==1)
                    //enc_topnum = enc_length+1;////////
                    odd = 1;
                else
                    //enc_topnum = enc_length;
                    odd =0;

                char enc_top[enc_length/2+odd],enc_bot[enc_length/2];

                for(int i =0 ;i<enc_length;i+=2){
                        enc_top[i/2]=enc_char[i];
                    if(!(odd=1 && i == enc_length -1))
                        enc_bot[i/2]=enc_char[i+1]; 

                }
                for(int i = 0;i<enc_length/2+odd;i++){
                    cout <<enc_top[i];
                }
                for(int i =0;i<enc_length/2;i++){
                    cout <<enc_bot[i];
                }
                cout << endl << endl;


            }
            else if(type==2){//decoder
                int dec_length;
                cout <<"Please enter sentences length: ";
                cin >>dec_length;
                char dec_char[dec_length];
        
                for(int i = 0;i <dec_length;i++ ){
                    cin >>dec_char[i];
                }
                int odd = 0;
                if(dec_length%2==1){
                    
                    dec_length+=1;
                    odd = 1;
                }
                
                for(int i =0;i<dec_length/2;i++){
                    cout<<dec_char[i];
                    if ( (i+dec_length/2)==(dec_length-1) && (odd == 1) ) 
                        break;
                    else
                        cout<<dec_char[i+dec_length/2];
                    
                }
                
                cout <<endl <<endl; 
                /*
                char enc_top[enc_length/2+1],enc_bot[enclength/2];

                for(int i =0 ;i<enc_length/2+1;i++){
                    if(i%2==0){
                        enc_top[i]=enc_char[2*i];
                    }
                    else{
                        enc_bot[i]=enc_char[2*i+1]; 
                    }

                }*/
                 

            }


        }

    }



    return 0;
}

