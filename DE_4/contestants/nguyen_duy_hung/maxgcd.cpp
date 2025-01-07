#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("maxgcd.inp");
    ofstream out("maxgcd.out");
    long long a,b;
    long long s=1;
    inp >> a >> b;
    if(a<b)
    {
        while(a>=2)
        {
            s*=a;
            a--;
        }
        out << s;
    }
    else
    {
        while(b>=2)
        {
            s*=b;
            b--;
        }
        out << s;
    }
}
