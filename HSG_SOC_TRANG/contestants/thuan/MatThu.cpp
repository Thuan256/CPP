#include <bits/stdc++.h>
using namespace std;

#define NAME "MatThu"

#define oo 1000007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n, m, x, i;
string s, str, num;
unordered_map<char, int> mp;

int main() {

    speedup sync

    cin >> s;

    while (i < s.size()) {
        if (isdigit(s[i])) {
            num.pb(s[i]);

            if (num.size() == 2 && stoi(num) > 0) break;
        }
        i++;
    }

    x = stoi(num);

    while (cin >> s) {
        str += s;
        for (char c: s) mp[c]++;
    }

    for (char c: str) if (mp[c] <= x) cout << c;

    return 0;
}
