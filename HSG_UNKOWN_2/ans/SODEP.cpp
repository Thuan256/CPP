#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int main()
{
    freopen("SODEP.INP","r",stdin);
    freopen("SODEP.OUT","w",stdout); 
    cin >> n;
    ll cnt = 0;
    for (ll i=1;i*i<=n;i++)
    if (n % i == 0)
    {
        j=n/i; 
	cnt += 2
	if (i==j)cnt--;
    }
    cout<<cnt;
    return 0;
}
