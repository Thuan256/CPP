#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("garbage.inp");
    ofstream out("garbage.out");
    int m,n;
    inp>>m>>n;
    vector<vector<long long>> a(m+1,vector<long long> (n+1,0));

    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            int num;
            inp>>num;
            a[i][j]=num;
        }
    }
    long long kq=0;
    vector<vector<int>> ds(m+1,vector<int> (n+1,0));
    vector<int> index(m+1);
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            ds[i][j]=max(max(ds[i-1][j-1]+a[i][j],ds[i-1][j+1]+a[i][j]),ds[i-1][j]+a[i][j]);
            if (kq<ds[i][j])
            {
                kq=ds[i][j];
                index[i]=j;
            }
            cout<<ds[i][j]<<" ";
        }
        cout<<endl;
    }
    out<<kq<<endl;
    for (int i=1;i<=m;i++)
        out<<index[i]<<endl;
    return 0;
}
