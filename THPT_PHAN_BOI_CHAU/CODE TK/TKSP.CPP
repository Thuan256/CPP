#include<bits/stdc++.h>
using namespace std;
int f[10000002];
int a[400005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen ("TKSP.inp", "r", stdin);
    freopen ("TKSP.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    int i=1;
    int j=i+k-1;
    long long kq=0;
    for (int x=1;x<=j;x++) f[a[x]]++;
    while (i<=n-k+1&&j<=n)
    {
        if (f[a[j]]<k)
        {
            j++;
            f[a[j]]++;
        }
        else
        {
            kq=kq+n-j+1;
            f[a[i]]--;
            i++;
        }
    }
    cout<<kq;
}
