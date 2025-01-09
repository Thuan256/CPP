#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("frog.inp");
    ofstream out("frog.out");
    long long n,k;
    inp >> k >> n;
    out << __gcd(n,k);
    out.close();
    return 0;
}
