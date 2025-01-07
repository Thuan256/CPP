#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("NUMPOS.INP");
    ofstream out("NUMPOS.OUT");
    long long k;
    inp>>k;
    if (k<=3)
        out<<k;
    else
    {

        long long kq=k*3-6;
        out<<kq;
    }
    return 0;
}
