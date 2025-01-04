#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("bai02.inp");
    ofstream out("bai02.out");
    int a,b;
    inp >> a >> b;
    vector<bool> hams(1e7+1,true);
    hams[0]=hams[1]=false;
    for(int p=2;p*p<=1e7;p++)
    {
        if(hams[p]==true)
        {
            for(int i=p*p;i<=1e7;i+=p)
                hams[i]=false;
        }
    }
    int k=0;
    int n;
    for(int j=a;j<=b;j++)
    {
        if(hams[j]==true)
        {
            string h=to_string(j);
            string s;
            for(int i=h.size()-1;i>=0;i--)
                s.push_back(h[i]);
            if(hams[stoi(s)]==true)
                k++;
        }
    }
    out << k;
    out.close();
    return 0;
}
