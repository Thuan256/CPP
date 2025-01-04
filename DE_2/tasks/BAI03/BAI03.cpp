#include <bits/stdc++.h>
#define maxn 50005
#define maxd 1000005
using namespace std;

int t,d,n;
int a[maxn];
int u[maxd];
long long s[maxn];

int main() {
   freopen("BAI03.inp","r",stdin);
   freopen("BAI03.out","w",stdout);
    ios::sync_with_stdio(false);
           cin>>d>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=0;i<=d-1;i++) u[i]=0;
        s[0]=0;u[0]++;
        int kq=0;
        for(int i=1;i<=n;i++) {
            s[i]=s[i-1]+a[i];
            int v=s[i]%d;
            kq+=u[v];
            u[v]++;
        }
        cout<<kq<<"\n";

}
