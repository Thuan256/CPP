#include <bits/stdc++.h>
using namespace std;
bool valid (int a, int b, int c) {
    return (a + b > c && a + c > b && b + c > a);
}
void daycon(int i,vector<pair<char,int>>& a,vector<pair<char,int>>& ds,int& kq, int& sl)
{
    if (i==a.size())
    {
        if (ds.size()==3 && (ds[0].first != ds[1].first && ds[1].first != ds[2].first && ds[0].first != ds[2].first))
        {
            sl++;
            if (valid(ds[0].second,ds[1].second,ds[2].second))
                kq++;
        }

    }
    else
    {
        if (ds.size()<=3)
        {
//            if (ds.size()==1)
//            {
//                if (a[i].first != ds[0].first)
//                {
//                    ds.push_back(a[i]);
//                    daycon(i+1,a,ds,kq, sl);
//                    ds.pop_back();
//                }
//                else
//                    daycon(i+1,a,ds,kq, sl);
//            }
//            else if (ds.size()==2)
//            {
//                if (a[i].first != ds[0].first && a[i].first != ds[1].first)
//                {
//                    ds.push_back(a[i]);
//                    daycon(i+1,a,ds,kq, sl);
//                    ds.pop_back();
//                }
//                else
//                    daycon(i+1,a,ds,kq, sl);
//            }
//            else
//            {
                ds.push_back(a[i]);
                daycon(i+1,a,ds,kq, sl);
                ds.pop_back();
                daycon(i+1,a,ds,kq, sl);

        }
        else
            daycon(i+1,a,ds,kq, sl);

    }
}
int main()
{
    ifstream inp("TRIANGLE.INP");
    ofstream out("TRIANGLE.OUT");
    int n;
    inp>>n;
    vector<pair<char,int>> a;
    for (int i=0;i<n;i++)
    {
        pair<char,int> ds;
        char str;
        int num;
        inp>>str>>num;
        ds={str,num};
        a.push_back(ds);
    }
    int kq=0;
    int sl=0;
    vector<pair<char,int>> ds;
    daycon(0,a,ds,kq, sl);
    out<<kq;
    return 0;
}
