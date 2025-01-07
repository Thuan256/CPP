#include <bits/stdc++.h>
using namespace std;

#define NAME "MAXNUM"

#define limit 1000007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

string s;
vector<int> vec;

int main() {

    speedup sync

    cin >> s;

    int n = s.size();

    FOD (i, n - 2, 0) {

        int val = s[i + 1] - '0';
        vec.pb(val);

        if (s[i] > s[i + 1]) {
            int x = (s[i] - '0');

            sort(vec.begin(), vec.end());
            int idx = --lower_bound(vec.begin(), vec.end(), x) - vec.begin();

            swap(x, vec[idx]);
            sort(vec.rbegin(), vec.rend());

            cout << s.substr(0, n - vec.size() - 1) << x;

            for (int v: vec) cout << v;

            return 0;
        }
    }

    cout << 0;

    return 0;
}

