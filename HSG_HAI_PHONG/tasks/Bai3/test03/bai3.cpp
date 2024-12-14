#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
long long a[202102], b[202102], c[202102], x[202102];;
long long n,m,res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if(fopen("BAI3.inp","r"))
    {
        freopen("BAI3.inp","r",stdin);
        freopen("BAI3.out","w",stdout);
    }
    cin >> m >> n;
    forinc(i,1,n + m) cin >> a[i] >> b[i] >> c[i];
    long long res = 0, sum = 0, t = 0;
    long long tmp = m + n;
    forinc(i,1,tmp)
    {
        if (c[i] == 1)
        {
            res += a[i];
            m--;
        }
        else
        if (c[i] == 2)
        {
           res += b[i];
           n--;
        }
        else
        {
            res += a[i];
            x[++t] = a[i] - b[i];
        }
    }
    sort(x + 1, x + t + 1, greater<long long>());
    forinc(i,1,n) res -= x[i];
    cout << res;
}
