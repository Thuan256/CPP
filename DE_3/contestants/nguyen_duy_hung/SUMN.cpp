#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("SUMN.inp");
    ofstream out("SUMN.out");
    int n;
    inp >>n;
    int s=0;
    while(n>0)
    {
        s+=n%10;
        n/=10;
    }
    out << s;
    out.close();
    return 0;
}
