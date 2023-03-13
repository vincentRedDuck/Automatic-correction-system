#include<bits/stdc++.h>
using namespace std;

int running(){
    string p, q;
    cout << "Enter first point:";
    cin >> p;
    cout << "Enter second point:";
    cin >> q;
    int pn, qn;
    for(int i=0; i<p.length(); ++i)
        if(p[i] == ','){
            pn = i;
            break;
        }

    for(int i=0; i<q.length(); ++i)
        if(q[i] == ','){
            qn = i;
            break;
        }

    int px = stoi(p.substr(1, pn-1));
    int py = stoi(p.substr(pn+1, p.length()-pn));
    int qx = stoi(q.substr(1, qn-1));
    int qy = stoi(q.substr(qn+1, q.length()-qn));
    if(px == 0 && py == 0 && qx == 0 && qy ==0)
        return 1;
     
    cout << "Distance: " << sqrt((px-qx)*(px-qx) + (py-qy)*(py-qy)) << "\n";
    return 0;
}


int main(){
    while(1)
        if(running())
            break;
}

