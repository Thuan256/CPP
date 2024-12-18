#include <bits/stdc++.h>
using namespace std;
const int MX=500500;
int t,n,q,i,j,k,prv,pos,sum,len,le,ri,a[MX],b[MX],sb[MX],nxt[MX],sm[20][MX],st[20][MX],lst[20][MX];
long long s[MX],vx,vy;
char snail[MX];
pair<long long,int> v[MX];
int main() {
  t=1;//scanf("%d",&t);
  while (t--) {
    scanf("%d%d%s",&n,&q,snail+1);
    prv=0;
    for (i=1; i<=n; i++) {
      b[i] = snail[i]-'0';
      sb[i]=sb[i-1]+b[i];
      if (b[i]==1) {
        nxt[prv]=i;
        nxt[i]=0;
        prv=i;
      }
    }
    nxt[prv]=n+1;
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      s[i]=s[i-1]+a[i];
    }
    prv=0;
    for (i=nxt[0]; i!=n+1; i=nxt[i]) {
      k=0;
      for (j=i; j<nxt[i]; j++) v[k++]={s[j]-s[i],j};
      sort(v,v+k);
      for (j=prv+1; j<=i; j++) {
        pos=lower_bound(v,v+k,make_pair(s[j-1]-s[i],-1))-v;
        if (pos==k) {
          st[0][j]=v[0].second;
          sm[0][j]=0;
          lst[0][j]=j;
        } else {
          st[0][j]=v[pos].second;
          sm[0][j]=1;
          lst[0][j]=j;
        }
      }
      prv=i;
    }
    for (j=1; j<20; j++) for (i=1; i<=prv; i++) {
      st[j][i]=st[j-1][i];
      sm[j][i]=sm[j-1][i];
      if (st[j][i]<prv) {
        sm[j][i]+=sm[j-1][st[j][i]+1];
        lst[j][i]=lst[j-1][st[j][i]+1];
        st[j][i]=st[j-1][st[j][i]+1];
      } else lst[j][i]=lst[j-1][i];
    }
    while (q--) {
      scanf("%d%d",&le,&ri);
      len=sb[ri]-sb[le-1];
      if (len==0) { puts("0"); continue; }
      i=le-1;
      sum=0;
      pos=le;
      for (j=19; j>=0; j--) if ((len>>j)&1) {
        sum+=sm[j][i+1];
        pos=lst[j][i+1];
        i=st[j][i+1];
      }
      vx=s[i]-s[pos-1];
      vy=s[ri]-s[pos-1];
      if (vx>=0 && vy<0) --sum;
      printf("%d\n",sum);
    }
  }
  return 0;
}
