#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("SNTO.inp");
    ofstream out("SNTO.out");
    int n;
    long long a;
    inp >> n;
    vector<bool> ham(1e7+1,true);
    ham[0]=ham[1]=false;
    for(int p=2;p*p<=1e7;p++)
    {
        if(ham[p]==true)
        {
            for(int i=p*p;i<=1e7;i+=p)
                ham[i]=false;
        }
    }
    int b=0;
    int s=0;
    while(n--)
    {
        inp >> a;
        if(ham[a]==true)
        {
            s++;
            if(a>=b)
                b=a;
        }
    }
    out << s << endl << b;
    out.close();
    return 0;
}
