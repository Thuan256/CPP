#include <bits/stdc++.h>
using namespace std;
//void daycon(int i,vector<int>& rs,vector<int>& a,vector<vector<int>>& ds)
//{
//    if (i==a.size())
//    {
//        if (rs.size()==2 && (rs[0]+rs[1])%2==0)
//            ds.push_back(rs);
//    }
//    else
//    {
//        rs.push_back(a[i]);
//        daycon(i+1,rs,a,ds);
//        rs.pop_back();
//        daycon(i+1,rs,a,ds);
//    }
//}
//    vector<vector<int>> ds;
//    vector<int> rs;
//    daycon(0,rs,a,ds);
//    cout<<ds.size();
//    for (int i=0;i<ds.size();i++)
//    {
//        for (int j=0;j<ds[i].size();j++)
//            cout<<ds[i][j]<<" ";
//        cout<<endl;
//    }
int main()
{
    ifstream inp("BAI03.INP");
    ofstream out("BAI03.OUT");
    int n;
    inp>>n;
    vector<int> a;
    map<long long,int> b;
    for (int i=0;i<n;i++)
    {
        int num;
        inp>>num;
        b[num]++;
        a.push_back(num);
    }

    map<long long,int> ds;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            int num=a[i]+a[j];
            if (num%2==0)
                ds[num/2]++;
        }
    }
    int kq=0;
    for (auto x:ds)
    {
        int num=x.first;
        if (b[num]>0)
            kq++;
    }
    out<<kq;
    inp.close();
    out.close();
    return 0;
}
