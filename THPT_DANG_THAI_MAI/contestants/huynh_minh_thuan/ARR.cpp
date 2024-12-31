#include <bits/stdc++.h>
using namespace std;

#define NAME "ARR"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n, num;
unordered_map<int, bool> mp;

int main() {

    speedup sync

    cin >> n;

    FOR (i, 1, n) {
        cin >> num;

        if (!mp[num]) cout << num << " ";

        mp[num] = true;
    }

    return 0;
}

