#include <bits/stdc++.h>
using namespace std;
void bansung( int i , vector<int>& a , int d , long long sum , vector<long long>& ds )
{
    if (i==a.size())
    {
        ds.push_back(sum);
    }
    else
    {
        if (d>0 && d<2)
        {
            bansung(i+1,a,d-1,sum+a[i],ds);
            bansung(i+1,a,2,sum,ds);
        }
        else if (d==2)
            bansung(i+1,a,d-1,sum+a[i],ds);
        else if (d==0)
            bansung(i+1,a,2,sum,ds);
    }
}
int main()
{
    ifstream inp("GAME.INP");
    ofstream out("GAME.OUT");
    int n;
    inp>>n;
    vector<int> a;
    for (int i=0;i<n;i++)
    {
        int num;
        inp>>num;
        a.push_back(num);
    }
    vector<int> dp(n,0);
    dp[0]=a[0]+a[1];
    dp[1]=a[0]+a[2];
    dp[2]=a[1]+a[2];
    if (n==1)
        out<<a[0];
    else if (n==2)
        out<<a[0]+a[1];
    else if (n==3)
        out<<max(max(dp[0],dp[1]),dp[2]);
    else
    {
        vector<long long> ds;
        bansung(0,a,2,0,ds);
        out<<*max_element(ds.begin(),ds.end());
    }
    inp.close();
    out.close();
    return 0;

}
