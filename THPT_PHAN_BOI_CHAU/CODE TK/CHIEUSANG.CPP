#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,m;
long long  a[N],b[N];
bool check(long long x)
{
    int j = 0;
    for(long long i=1;i<=n;i++)
    {
        while(j < m && b[j+1] <= a[i])
            j++;
        if(abs(b[j] - a[i]) > x && abs(b[j+1] - a[i]) > x)
            return false;
    }
    return true;
}
int main()
{
    freopen("CHIEUSANG.INP","r",stdin);
    freopen("CHIEUSANG.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    for(long long i=1;i<=m;i++)
        cin>>b[i];
    b[0] = -3e9, b[m+1] = 3e9;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    long long l = 0,r = 2e9, tam;
    while(l <= r)
    {
        long long  mid = l + r >> 1;
        if(check(mid))
        {
            tam = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout<<tam;
}
