#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("bai01.inp");
    ofstream out("bai01.out");
    long long a,m,n,b,i,j;
    inp >> a >> b >> n >> m;
    long long s=1e9;
    i=pow(a,n);
    j=pow(b,m);
    out << i%s+j%s;
    out.close();
    return 0;
}
