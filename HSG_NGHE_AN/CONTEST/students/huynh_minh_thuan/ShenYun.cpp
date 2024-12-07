#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("ShenYun.inp");
    ofstream out("ShenYun.out");

    ll N, x, y;
    inp >> N >> x >> y;

    out << N / (x * (y / __gcd(x, y)));
    return 0;
}
