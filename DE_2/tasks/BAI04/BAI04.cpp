#include <bits/stdc++.h>
#define ft first
#define sc second
#define maxn 100005

using namespace std;
typedef pair<int,int> II;

int n;
II a[maxn];
int x[maxn], b[maxn];

int get(int u) {
    int kq=0;
    while (u>0) {
        kq+=b[u];
        u&=(u-1);
    }
    return kq;
}
void update(int u,int val) {
    while (u<=n) {
        b[u]+=val;
        u+=u&(-u);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("BAI04.INP","r",stdin);
    freopen("BAI04.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) {
        int u, v; cin >> u >> v;
        a[i]=II(v,u);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) x[i]=a[i].sc;
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++) a[i].sc=lower_bound(x+1,x+n+1,a[i].sc)-x;
    for(int i=1;i<=n;i++) b[i]=0;
    long long ans=0;
    for(int i=1;i<=n;i++) {
        ans+=get(n+1-a[i].sc);
        update(n+1-a[i].sc,1);
    }
    cout << ans;
}
