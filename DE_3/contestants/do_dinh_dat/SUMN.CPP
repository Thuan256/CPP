#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("SUMN.INP");
    ofstream out("SUMN.OUT");
    string n;
    inp>>n;
    int kq=0;
    int i=0;
    while (i<n.size())
    {
        kq+=n[i]-'0';
        i++;
    }
    out<<kq;
    return 0;

}
