#include <bits/stdc++.h>
using namespace std;

#define NAME "LUCKYSUM"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int L, R;
ull ans = 0;

int main() {

    speedup sync

    string num = "4";

    cin >> L >> R;

    while (true) {
        if (num.size() == 10) break;

        int x = stoi(num);

        if (x >= R) {
            ans += (R - L + 1) * x;
            break;
        } else if (x >= L) {
            ans += (x - L + 1) * x;
            L = x + 1;
        }

        FOD (i, num.size() - 1, 0) {

            if (num[i] == '4') {
                num[i] += 3;
                break;
            } else {
                num[i] -= 3;
                if (i == 0) num = "4" + num;
            }
        }
    }

    cout << ans;

    return 0;
}

