#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long luythua(long long n)
{
    int i=1;
    long long kq=1;
    while (i<=n)
    {
        kq*=i;
        i++;
        kq%=mod;
    }
    return kq;
}

int main()
{
    ifstream inp("MAXGCD.INP");
    ofstream out("MAXGCD.OUT");
    long long a,b;
    inp>>a>>b;
    if (a<b)
        out<<luythua(a);
    else
        out<<luythua(b);
    return 0;
}
