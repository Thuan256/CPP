#include <bits/stdc++.h>

using namespace std;
bool ngto(long x){
    if(x<2) return 0;
        for(int i=2;i*i<=x;i++)
            if(x%i==0)
        return 0;
return 1;
    }
bool bacthang(long x){
int du;
if (x<=10)
    return 0;
while(x>1){
    du=x%10;
    x=x/10;
    if(du<=x%10)
        return 0;
    }
    return 1;
}
int main()
{int i,d,n;
long a[100003];

freopen("BAI02.INP","r",stdin);
freopen("BAI02.OUT","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
       cin>>a[i];
       d=0;
    for(i=1;i<=n;i++)
     if (bacthang(a[i])&& ngto(a[i]))
       d++;
    cout<<d;
     return 0;
}
