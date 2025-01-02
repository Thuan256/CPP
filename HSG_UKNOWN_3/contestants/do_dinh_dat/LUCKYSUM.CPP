#include <bits/stdc++.h>
using namespace std;
void daycon(int i,int j,vector<int>& a,vector<int>& ds,vector<long long>& rs)
{
    if (i==j)
    {
        long long num=0;
        for (auto x:ds)
            num=num*10+x;
        rs.push_back(num);
    }
    else
    {
        for (int x:a)
        {
            ds.push_back(x);
            daycon(i+1,j,a,ds,rs);
            ds.pop_back();
        }
    }
}
int main()
{
    ifstream inp("LUCKYSUM.INP");
    ofstream out("LUCKYSUM.OUT");
    int L,R;
    inp>>L>>R;
    vector<int> a={4,7};
    vector<int> ds;
    vector<long long> rs;

    for (int j=1;j<=10;j++)
    {
        daycon(0,j,a,ds,rs);
    }
    long long kq=0;
    for (auto x:rs)
    {
        if (x>=R)
        {
            kq+=(R-L+1)*x;
            break;
        }
        else
        {
            if (x>=L){
                kq+=(x-L+1)*x;
                L=x+1;}
        }
    }
    out<<kq;
    return 0;
}
