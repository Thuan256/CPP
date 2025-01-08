#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("demso.inp");
    ofstream out("demso.out");
    long long m,n,q,a;
    inp >> m >> n >> q;
    vector<int> A;
    while(q--)
    {
        inp >> a;
        int k=0;
        for(int i=1;i<=n;i++)
        {
            if(a%i==0 && a/i<=m)
                k++;
        }
        out << k << endl;
    }
    out.close();
    return 0;

}
