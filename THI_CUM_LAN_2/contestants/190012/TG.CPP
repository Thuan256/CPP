#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("TG.INP");
    ofstream out("TG.OUT");
    long long L,R;
    inp>>L>>R;
    long long i=R-1;
    long long chenhlech=(L+R)*(R-L+1)/2;
    long long kq=0;
    while(i>=(R+L)/2) {
        long long sumtrai=(L+i)*(i-L+1)/2;
        long long sumphai=(R+i+1)*(R-i)/2;
        long long sl=abs(sumtrai-sumphai);
        if (sl<chenhlech) {
            chenhlech=sl;
            kq=i;
        }
        i--;
    }
    out<<kq;
    return 0;

}
