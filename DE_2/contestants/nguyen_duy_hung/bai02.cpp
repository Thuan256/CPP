#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("bai02.inp");
    ofstream out("bai02.out");
    int n,a;
    inp >> n;
    vector<bool> ham(2e6+1,true);
    ham[0]=ham[1]=false;
    for(int p=2;p*p<=2e6;p++)
    {
        if(ham[p]==true)
        {
            for(int i=p*p;i<=2e6;i+=p)
                ham[i]=false;
        }
    }
    int k=0;
    while(n--)
    {
        inp >> a;
        if(a>=11 && ham[a]==true)
            {
                int h=1;
                string s=to_string(a);
                for(int i=0;i<s.size()-1;i++)
                {
                    if(s[i]>=s[i+1])
                        h=0;
                }
                if(h==1)
                    k++;

            }
    }
    out << k;
    out.close();
    return 0;
}
