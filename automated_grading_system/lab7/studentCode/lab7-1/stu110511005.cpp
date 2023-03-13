#include<iostream>
using namespace std;

struct CARD{
    char suit;
    int value;
};
const int MAX_SIZE=10;

int main() {
    CARD card[MAX_SIZE];
    int snum[10]; int S=0;
    int hnum[10]; int H=0;
    int dnum[10]; int D=0;
    int cnum[10]; int C=0;
    for (int i=0 ; i<10 ; i++) {
        cout << "#" << i+1 << " card suit: ";
        cin >> card[i].suit;
        cout << "#" << i+1 << " card number: ";
        cin >> card[i].value;
    }
    for (int i=0 ; i<10 ; i++) {
        if (card[i].suit=='s') {
            snum[S]=card[i].value;
            S++;
        }
        else if (card[i].suit=='h') {
            hnum[H]=card[i].value;
            H++;
        }
        else if (card[i].suit=='d') {
            dnum[D]=card[i].value;
            D++;
        }
        else if (card[i].suit=='c') {
            cnum[C]=card[i].value;
            C++;
        }
    }

    for (int i=0 ; i<S ; i++) {
        for (int j=0 ; j<S ; j++) {
            int tmp;
            if (snum[i]>snum[j]) {
                tmp=snum[i];
                snum[i]=snum[j];
                snum[j]=tmp;
            }
        }
    }
    for (int i=0 ; i<H ; i++) {
        for (int j=0 ; j<H ; j++) {
            int tmp;
            if (hnum[i]>hnum[j]) {
                tmp=hnum[i];
                hnum[i]=hnum[j];
                hnum[j]=tmp;
            }
        }
    }
    for (int i=0 ; i<D ; i++) {
        for (int j=0 ; j<D ; j++) {
            int tmp;
            if (dnum[i]>dnum[j]) {
                tmp=dnum[i];
                dnum[i]=dnum[j];
                dnum[j]=tmp;
            }
        }
    }
    for (int i=0 ; i<C ; i++) {
        for (int j=0 ; j<C ; j++) {
            int tmp;
            if (cnum[i]>cnum[j]) {
                tmp=cnum[i];
                cnum[i]=cnum[j];
                cnum[j]=tmp;
            }
        }
    }

    cout << "\nafter sort" << endl;
    int j=S-1;
    int k=H-1;
    int l=D-1;
    int m=C-1;
    for (int i=0 ; i<S ;i++) {
        cout << "suit: Spades number: " << snum[j] << endl;
        j--;
    }
    for (int i=0 ; i<H ;i++) {
        cout << "suit: Heart number: " << hnum[k] << endl;
        k--;
    }
    for (int i=0 ; i<D ;i++) {
        int j=0;
        cout << "suit: Diamond number: " << dnum[l] << endl;
        l--;
    }
    for (int i=0 ; i<C ;i++) {
        int j=0;
        cout << "suit: Club number: " << cnum[m] << endl;
        m--;
    }
    return 0;
}

