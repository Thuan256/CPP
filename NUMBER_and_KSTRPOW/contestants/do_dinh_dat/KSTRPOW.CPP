#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("KSTRPOW.INP");
    ofstream out("KSTRPOW.OUT");
    string S,T;
    int k;
    inp>>S>>T>>k;
    string xau;
    for (int i=0;i<k;i++)
        xau+=S;
    if (xau==T)
        out<<"YES";
    else
        out<<"NO";
    inp.close();
    out.close();
    return 0;
}
