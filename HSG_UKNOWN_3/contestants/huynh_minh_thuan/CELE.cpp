#include <bits/stdc++.h>
using namespace std;

#define NAME "CELE"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin);
//freopen(NAME".out", "w", stdout);

int n, a[limit], removed[limit];
priority_queue<pair<int, int>> pq;
ll ans = 0;

int main() {

    speedup sync

    cin >> n;

    FOR (i, 1, n) {
        cin >> a[i];
        pq.emplace(a[i], -i);
    }

    while (!pq.empty()) {
        pair<int, int> p = pq.top();

        int val = p.first, i = -p.second;
        pq.pop();

        removed[i] = removed[i - 1] + 1;
        removed[i + 1] = (!!removed[i + 1]) * (removed[i] + 1);

        ans += val + a[i - removed[i - 1] - 1] + a[i + removed[i + 1] + 1];
    }

    cout << ans;

    return 0;
}


