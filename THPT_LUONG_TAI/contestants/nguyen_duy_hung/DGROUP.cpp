#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("DGROUP.INP");
    ofstream out("DGROUP.OUT");
    int a,b,c;
    inp >> a >> b >> c;
    int k=0;
    for(int j=1;j<=b;j++)
    {
        if(a-j*2+b-j>=6 && a>=j*2 && b>=j)
        {
            k=j;
        }
    }
    out << k;
    out.close();
    return 0;

}
