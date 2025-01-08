#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("DEMSO.INP");
    ofstream out("DEMSO.OUT");
    int m,n;
    inp>>m>>n;
    map<int,int> a;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
            a[i*j]++;
    }
    int q;
    inp>>q;
    for (int i=0;i<q;i++)
    {
        int num;
        inp>>num;
        out<<a[num]<<endl;
    }
    return 0;
}
