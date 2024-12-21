#include <bits/stdc++.h>
#define N int(1e6)
#define ll long long
using namespace std;
int s[N+3];
int n, M;
ll ans = 0;
int main()
{
    freopen("DAYCON.INP","r",stdin);
    freopen("DAYCON.OUT","w",stdout);
    cin >> n >> M;
    for (int x, i=1; i<=n; i++)
    {
   	cin >> x;
	s[i] = s[i-1] + x;
    }
    for (int i=1; i<=n; i++)
    {
 	int x = s[i] - M;
	int j =  lower_bound(s,s+i,x)-s;
	x = i - j;
	ans += x * 1LL;
    }
    cout << ans;
    return 0;
}
