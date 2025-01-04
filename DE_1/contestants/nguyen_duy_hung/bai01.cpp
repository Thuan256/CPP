
#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("bai01.inp");
    ofstream out("bai01.out");
    long long n;
    inp >> n;
    vector<bool> hams(162,false);
    for(long long p=1; p*p<=162; p++) {
        hams[p*p]=true;
    }
    int s=0;
    while(n>=1) {
        s+=n%10;
        n=n/10;
    }
    if(hams[s]==true)
        out << s;
    else
        out << s%11;
    out.close();
    return 0;
}
