#include<bits/stdc++.h>
#define N 10000000
using namespace std;
int nt[N];  
int l,r;
int n,k;
void sangnt(int n)
{
    fill(nt+2,nt+n+1,1);
    for (int i=2;i*i<=n;i++)
    if (nt[i] == 1)
	for (int j=i*i;j<=n;j+=i) nt[j]=0;
}
int tongcs(int x)
{
    int s = 0;
    while (x>0)
    {
	s += x % 10;
	x/=10;
    }
    return s;
}
int main()
{
    freopen("PASSWORD.INP", "r", stdin);
    freopen("PASSWORD.OUT", "w", stdout);
    cin >> l >> r;
    sangnt(r);
    for (int x = l; x <= r; x++)
    if (nt[x] == 1 && nt[tongcs(x)] == 1)
        cout << x << " ";    
    return 0;
}
