#include <bits/stdc++.h>
using namespace std;
void daycon(int i,int s,int sum,vector<int>& a,vector<int>& ds)
{
    if (i==a.size())
    {
        if (sum<=s)
            ds.push_back(sum);
    }
    else
    {
        daycon(i+1,s,sum+a[i],a,ds);
        daycon(i+1,s,sum,a,ds);
    }
}
int main()
{
    ifstream inp("PO.INP");
    ofstream out("PO.OUT");
    int n,s,Q;
    inp>>n>>s>>Q;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int num;
        inp>>num;
        a.push_back(num);
    }
    vector<int> ds;
    daycon(0,s,0,a,ds);
    int MAX=*max_element(ds.begin(),ds.end());
    int d=0;
    for (int x:ds)
    {
        if (x==MAX)
            d++;
    }
    if (Q==1)
        out<<MAX;
    else
        out<<MAX<<endl<<d;
    inp.close();
    out.close();
    return 0;

}
