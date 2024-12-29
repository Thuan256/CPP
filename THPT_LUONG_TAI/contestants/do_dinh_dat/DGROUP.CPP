#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("DGROUP.INP");
    ofstream out("DGROUP.OUT");
    int n,m,k;
    inp>>n>>m>>k;
    int kq=0;
    for (int i=0;i<=k;i++)
    {
        int nam=n;
        int nu=m;
        nam-=k-i;
        nu-=i;
        int j=0;
        while (j*2<=nam && j<nu)
            j++;
        if (j*2>nam || j>nu)
            j--;
        if (kq<j)
            kq=j;
    }
    out<<kq;
    inp.close();
    out.close();
    return 0;
}
