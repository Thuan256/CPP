                     /*chat nhi phan, dem phan phoi, 2 con tro*/
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;
int n,a[50001];
map<long ,long> d;
int bs (int l, int r, int res)
{
    if (l>r)
        return 0;
    int mid=(l+r)/2;
    if (a[mid]==res)
        return mid;
    if (a[mid]>res)
        return bs (l,mid-1,res);
    return bs (mid+1,r,res);
}
main()
{
    freopen("bai03.inp","r",stdin);
    freopen("bai03.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    if (n<=20000){
    sort (a+1,a+n+1);
    int res=0;
    for (int i=1; i<=n-1; i++)
        for (int j=i+1; j<=n; j++)
            if ((a[i]+a[j])%2==0)
            {
                int p=(a[i]+a[j])/2;
              if (bs(1,n,p)!=0 && d[p]==0){
                res++;
                d[p]=1;
              }
            }
    cout<<res;
    }
    else{
            for (int i=1;i<=n;i++) d[a[i]]++;
        int res=0;
        for (int i=1;i<=10000;i++){
        int j=i,k=i;
        if (d[i]>=3) res+=d[i];
    else
        while (j>0 && k<10000){
            j--;
            k++;
            if (d[j]>0 && d[k]>0) {res+=d[i];
            j=0;
            }
        }
        }
        cout<<res;
    }
}
