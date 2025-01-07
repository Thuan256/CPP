#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("SQUARE.INP");
    ofstream out("SQUARE.OUT");
    string xau;
    inp>>xau;
    int kq=0;
    for (int i=0;i<xau.size();i++)
    {
        kq+=(xau[i]-'0')*(xau[i]-'0');
    }
    out<<kq;
    return 0;
}
