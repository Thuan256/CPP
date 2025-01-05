#include<bits/stdc++.h>
using namespace std;
long long luythua(long long x,long long y)
{
    long long kq=1;
    long long base=1000000000;
    while(y>0)
    {
        if (y%2==1)
            kq*=x;
        kq%=base;
        x*=x;
        x%=base;
        y/=2;
    }
    return kq;
}
int main()
{
    ifstream inp("BAI01.INP");
    ofstream out("BAI01.OUT");
    long long a,b;
    long long n,m;
    inp>>a>>b>>n>>m;
    out<<luythua(a,n)+luythua(b,m);
    return 0;
}
