#include <bits/stdc++.h>
using namespace std;
vector<bool> snt(int n)
{
    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;
    for (int p=2;p*p<=n;p++)
    {
        if (prime[p]==true)
        {
            for (int i=p*p;i<=n;i+=p)
                prime[i]=false;
        }
    }
    return prime;
}
int main()
{
    ifstream inp("BAI1.INP");
    ofstream out("BAI1.OUT");
    vector<bool> p=snt(32767);
    vector<int> a;
    int num;
    while (inp>>num)
        a.push_back(num);
    if (a.size()==0 || a.size()==1 || a.size()==2)
        out<<0;
    else
    {
        int index=0;
        for (int i=1;i<a.size()-1;i++)
        {
            if (a[i-1]>0 && a[i+1]>0 && p[a[i-1]]==true && p[a[i+1]]==true )
                        index=i;
        }
        if (index>0)
            out<<index+1;
        else
            out<<index;
    }
    return 0;
}
