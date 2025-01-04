#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
using namespace std;
ll n,a[5010],res;
map <ll,ll> d;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("bai03.inp","r",stdin);
    freopen("bai03.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        d[a[i]]++;
    }
    for (int i=1; i<=n-1; i++)
        for (int j=i+1; j<=n; j++)
            if ((a[i]+a[j])%2==0)
                if ((a[i]==a[j]&&d[(a[i]+a[j])/2]>2)||a[i]!=a[j])
                {
                    res+=d[(a[i]+a[j])/2];
                    d[(a[i]+a[j])/2]=0;
                }
    cout << res;
}
