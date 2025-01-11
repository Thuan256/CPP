#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
string s,t;
pair <string,int> a[1000006];
bool cmp(pair <string,int> c,pair <string,int> d)
{
    string x=c.fi,y=d.fi;
    while(x[0]=='0') x.erase(0,1);
    while(y[0]=='0') y.erase(0,1);
    if(x.size()>y.size()) return false;
    else if(x.size()<y.size()) return true;
    else
    {

        if(x>y) return false;
        else if(x<y) return true;
        else return c.se<d.se;
    }
}
long m=1;
int main()
{
freopen("tachmaso.inp","r",stdin);
    freopen("tachmaso.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
       cin>>s;
    s=s+' ';
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            t=t+s[i];
        else
        {
            if(!t.empty())
            {
                a[m].fi=t;
                a[m].se=m;
                m++;
            }
        t.clear();
        }
    }
    sort(a+1,a+m,cmp);
    for(long long i=1;i<m;i++) cout<<a[i].fi<<" ";
}
