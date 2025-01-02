#include <bits/stdc++.h>
using namespace std;


int main(){
    ifstream inp("TG.inp");
    ofstream out("TG.out");
    int l,r,c;
    inp>>l>>r;
    c=((r+l)/2)+1;
    out<< c;
    return 0;
}
