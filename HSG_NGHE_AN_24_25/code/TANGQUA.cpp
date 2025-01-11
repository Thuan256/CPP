#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1000006],cs = 1,x;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("TANGQUA.inp", "r", stdin);
    freopen("TANGQUA.out", "w", stdout);
    cin >> n;
    memset(a,0,sizeof a);
    cs = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x] = 1;
        while(a[cs])
            cs++;
        cout << cs << ' ';
    }
}
