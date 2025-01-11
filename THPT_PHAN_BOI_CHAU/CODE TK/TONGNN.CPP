#include <bits/stdc++.h>
using namespace std;
long long ans=1e18;
long long m,n,d,k,x;

int main()
{
   freopen("tongnn.inp","r",stdin);
   freopen("tongnn.out","w",stdout);
   cin>>m>>n;
    if(n%m!=0)
    {
        cout<<-1;
        return 0;
    }
  k=n/m;
for(long long x=1;x*x<=k;x++)
    if(k%x==0)
{
    long long y=k/x;
    if (__gcd(x,y) == 1) ans=min(ans,(x+y)*m);
}
    cout<<ans;
    return 0;
}
