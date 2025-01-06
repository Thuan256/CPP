#include <bits/stdc++.h>
using namespace std;

#define NAME "TACHMASO"

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
multimap<ull, string> mp;
int i;

int main() {

    speedup sync

    cin >> s;

    while (i < s.size()) {

        if (isdigit(s[i])) {
            string str = "";

            while (isdigit(s[i])) str.pb(s[i++]);

            ull num = str.size() > 19 ? ULLONG_MAX : stoull(str);

            mp.insert({num, str});
        }

        i++;
    }

    for (auto val: mp) cout << val.second << " ";

    return 0;
}

