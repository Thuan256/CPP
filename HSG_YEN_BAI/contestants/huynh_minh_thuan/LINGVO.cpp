#include <bits/stdc++.h>
using namespace std;

#define NAME "LINGVO"

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

unordered_map<int, string> mp;
int n, num;

bool comp(string a, string b) {
    FOR (i, 0, min(a.size(), b.size()) - 1) {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }

    return true;
}

int main() {

    speedup sync

    FOR (i, 0, 9) cin >> mp[i];

    cin >> n;

    while (n--) {
        cin >> num;
        vector<string> vec;

        string ans;

        if (num < 10) ans = mp[num];
        else {

            while (num != 0) {
                vec.pb(mp[num % 10]);
                num /= 10;
            }

            sort(vec.begin(), vec.end(), comp);
            ans = *vec.begin();
        }

        cout << ans << endl;
    }

    return 0;
}
