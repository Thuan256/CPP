#include <bits/stdc++.h>
using namespace std;
void daycon(int i,vector<int>& a,int k,vector<int>& ds1,vector<int>& ds2)
{
    if (i==a.size())
    {
        if (ds1.size()==2 && accumulate(ds1.begin(),ds1.end(),0)%k != 0)
            copy(ds1.begin(), ds1.end(), back_inserter(ds2));
    }
    else
    {
        daycon(i+1,a,k,ds1,ds2);
        ds1.push_back(a[i]);
        daycon(i+1,a,k,ds1,ds2);
        ds1.pop_back();
    }
}
int main()
{
    ifstream inp("NUMBER.INP");
    ofstream out("NUMBER.OUT");
    int n,k;
    inp>>n>>k;
    vector<int> a;
    for (int i=0;i<n;i++)
    {
        int num;
        inp>>num;
        a.push_back(num);
    }
    vector<int> ds1;
    vector<int> ds2;
    daycon(0,a,k,ds1,ds2);
    set<int> ds(ds2.begin(),ds2.end());
    out<<ds.size();
    inp.close();
    out.close();
    return 0;

}
