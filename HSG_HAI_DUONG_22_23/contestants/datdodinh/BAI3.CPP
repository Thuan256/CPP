#include <bits/stdc++.h>
using namespace std;
void chonqua(int m,int i,int trai,int phai ,long long sum , vector<int>& a,vector<int>& ds)
{
    if (i==m)
        ds.push_back(sum);
    else
    {
        chonqua(m,i+1,trai+1,phai,sum+a[trai],a,ds);
        chonqua(m,i+1,trai,phai-1,sum+a[phai],a,ds);
    }
}
int main()
{
    ifstream inp("BAI3.INP");
    ofstream out("BAI3.OUT");
    int n,m;
    inp>>n>>m;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int num;
        inp>>num;
        a.push_back(num);
    }
    vector<int> ds;
    chonqua(m,0,0,n-1,0,a,ds);
    out<<*max_element(ds.begin(),ds.end());
    inp.close();
    out.close();
    return 0;
}
