#include <bits/stdc++.h>
using namespace std;

#define NAME "SUBSTR"

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

int k, one, ans, i, j;
string s;
pair<int, int> zero;

int main() {

    speedup sync

    cin >> k >> s;

    while (i < s.size()) {

        j = i;
        one = 0;

        while (j < s.size()) {
            one += s[j] == '1';

            if (one == k) {
                ans++;
                j++;

                while (s[j] == '0') {
                    ans++;
                    j++;
                }

                break;
            }
            j++;
        }

        i++;
    }

    cout << ans;

    return 0;
}

