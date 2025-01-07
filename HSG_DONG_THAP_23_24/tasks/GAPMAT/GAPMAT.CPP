#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const long long oo=1e18;
typedef pair <long long, int> ii;
vector <ii> a[N];
long long d[N], d1[N],dn[N];
int n, m, dem;
long long res=1e18;
void doctep(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x, y, z;
        cin>>x>>y>>z;
        a[x].push_back(ii(z, y)); // do dai va dinh
        a[y].push_back(ii(z, x)); // do dai va dinh
    }
    for(int i=0; i<=n; i++) a[i].push_back(ii(0,0));
}
void dtra(int x){
    priority_queue <ii,vector<ii>,greater<ii> >pq;
    for (int i=1;i<=n;i++) d[i]=oo;
    d[x]=0;
    pq.push(ii(0,x));
    while (!pq.empty()){
        int u=pq.top().second;
        long long du=pq.top().first;
        pq.pop();
        for (int i=0;int v=a[u][i].second;i++)
            if (d[v]>du+a[u][i].first){
                d[v]=du+a[u][i].first;
                pq.push(ii(d[v],v));
        }
    }
}
main(){
    //freopen("GAPMAT.INP","r", stdin);
    //freopen("GAPMAT.OUT","w", stdout);
    doctep();
    dtra(1);
    for( int i=1; i<=n; i++) d1[i]=d[i];
    dtra(n);
    for( int i=1; i<=n; i++) dn[i]=d[i];

    for( int i=1; i<=n; i++){
        res= min(d1[i]+dn[i], res);
    }

    for( int i=1; i<=n; i++){
        if (d1[i]+dn[i]== res) dem++;
    }
    cout<<dem;
}




