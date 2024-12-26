#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("BAI1.INP");
    ofstream out("BAI1.OUT");
    int a,h;
    float x;
    inp>>a>>x>>h;
    float sum = h + tan(x/180*3.14159)*a;
    out<<fixed<<setprecision(3)<<sum;
    inp.close();
    out.close();
    return 0;
}
