#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[1000006],dp1[1000006],dp2[1000006],sum1[1000006],sum2[1000006];
const ll mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DODANK.inp", "r", stdin);
    freopen("DODANK.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum1[i] = sum2[i] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        if(i < k)
        {
            dp1[i] = 1;
            dp2[i] = a[i];
        }
        else
        {
            dp1[i] = (sum1[i-k] + 1)%mod;
            dp2[i] = (sum2[i-k] + a[i] * dp1[i]%mod)%mod;
        }
        sum1[i] = (sum1[i-1] + dp1[i])%mod;
        sum2[i] = (sum2[i-1] + dp2[i])%mod;
    }
    cout << sum2[n];
}
