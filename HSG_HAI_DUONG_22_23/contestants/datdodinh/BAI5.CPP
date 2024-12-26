#include <bits/stdc++.h>
using namespace std;
void daycon(int i,vector<int>& rs,vector<int>& a,vector<int>& ds)
{
    if (i==a.size())
    {
        if (rs.size()==3)
            ds.push_back(rs[0]*rs[1]*rs[2]);
    }
    else
    {
        rs.push_back(a[i]);
        daycon(i+1,rs,a,ds);
        rs.pop_back();
        daycon(i+1,rs,a,ds);
    }
}
int main()
{
    ifstream inp("BAI5.INP");
    ofstream out("BAI5.OUT");
    int n;
    inp>>n;
    vector<int> a;
    for (int i=0;i<n;i++)
    {
        int num;
        inp>>num;
        a.push_back(num);
    }
    vector<int> rs;
    vector<int> ds;
    daycon(0,rs,a,ds);
    long long kq=accumulate(ds.begin(),ds.end(),0);
    out<<kq;
    return 0;
}
