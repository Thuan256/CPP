#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, ans;
double a[maxn], b[maxn], c[maxn];
int low(int u, int v, double x){
    int l=u, r=v + 1;
    while(r - l > 1){
        int mid = (l + r)/2;
        if(c[mid] < x) {
            l = mid;
        }else r = mid;
    }
    return l;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT","w",stdout);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];
    for(int i=1; i<=n; ++i){
        double val = a[i]/b[i];
        int u = low(1, ans + 1, val);
        if(u > ans) ++ans;
        c[u] = val;
    }
    cout << ans;
    return 0;
}

