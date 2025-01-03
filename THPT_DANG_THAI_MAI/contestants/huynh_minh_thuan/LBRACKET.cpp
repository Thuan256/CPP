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
int last = -1, L = 1, R = 1, ans_L, ans_R, ans, i = 1;
pair<int, int> p;

int main() {

    speedup sync

    string s;
    cin >> s;

    while (L <= s.size()) {

        if (s[L - 1] == '(') {
            p.fi++;

            R = L + 1;

            while (R <= s.size() && s[R] == ')' && p.se <= p.fi) {
                p.se++;
                R++;
            }

            cout << R - L + 1 << endl << L << " " << R << endl;
        }
        L++;

//        if (s[R - 1] == ')') {
//            if (p.fi) p.se++;
//            else L = R;
//        } else p.fi++;
//
//        if (p.fi && p.se && p.fi == p.se) {
//
//            int _L = L;
//
//            if (L == last) {
//                _L = last;
//            } else last = R;
//
//            if (R - _L > ans) {
//                ans = R - _L + 1;
//                ans_L = _L;
//                ans_R = R;
//            }
//            p = {0, 0};
//            L = R;
//
//        }
//        R++;
    }

//    cout << ans << endl << ans_L << " " << ans_R;

    return 0;
}

