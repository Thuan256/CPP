#include<bits/stdc++.h>
using namespace std;
long long a,b,res;
bool d[100000000];
long long daonguoc(long long n)
{
  long long m=0;
  while(n>0)
  {
    m=m*10+n%10;
    n=n/10;
  }
  return m;
}
int main()
{
 freopen("BAI02.INP","r",stdin);
freopen("BAI02.OUT","w",stdout);
  memset(d,0,sizeof(d));
  d[1]=1;
  for (long long i=2; i*i<=10000000; i++)
        if (d[i]==0) {
            for (long long j=2; i*j<=10000000; j++)
                d[i*j]=1;
        }
        //for(int i=1;i<=10;i++)
          //  cout<<d[i]<<" ";
  scanf("%d%d",&a,&b);
  for(long long i=a; i<=b; i++)
  {
    if(d[i]==0){
         long long m=daonguoc(i);
        if (d[m]==0)
       // cout<<i<<" ";
      res++;}
  }

  printf("%d",res);
}
