#include <bits/stdc++.h>
#define N 100000
#define ll long long
using namespace std;
int a[N+3];
int n,k;
ll ans;
map (int, int) M;
int main()
{
    freopen("TERACING.INP","r",stdin);
    freope("TERACING.OUT","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i<=n; i++)
    {
     	if (a[i] > k) ans += M[a[i]-k];
	M[a[i]]++;
    }
    return 0;
}
