#include <bits/stdc++.h>
using namespace std;

#define NAME "LBRACKET"

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
int last = 0, L = -1, R = -1, ans = 0;
pair<int, int> p;

int main() {

    speedup sync

    string s;
    cin >> s;

    FOR (i, 0, s.size() - 1) {
        if (s[i] == '(') p.fi++;
        else p.se++;

        if (p.fi == p.se) {
            int len = p.se * 2;

            if (len > ans) {
                ans = len;
                L = last;
                R = i;
            }
        } else if (p.fi < p.se) {
            p = {0, 0};
            last = i + 1;
        }
    }

    last = s.size() - 1;
    p = {0, 0};

    FOD (i, s.size() - 1, 0) {
        if (s[i] == '(') p.fi++;
        else p.se++;

        if (p.fi == p.se) {
            int len = p.se * 2;

            if (len > ans) {
                ans = len;
                L = i;
                R = last;
            }
        } else if (p.fi > p.se) {
            p = {0, 0};
            last = i - 1;
        }
    }

    cout << ans << endl << ++L << " " << ++R;

    return 0;
}

