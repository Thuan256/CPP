#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI03"

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

int n, a[limit];
multiset<int> s;
unordered_map<int, int> freq;
unordered_set<int> ans;

int main() {

    speedup sync

    cin >> n;

    FOR (i, 1, n) {
        cin >> a[i];
        if (n <= 3e3) s.insert(a[i]);
        else freq[a[i]]++;
    }

    if (n <= 3e3) {
        FOR (i, 1, n - 1) {
            FOR (j, i + 1, n) {
                int sum = a[i] + a[j];
                if (sum % 2 == 0 && s.count(sum / 2)) ans.insert(sum / 2);
            }
        }

        cout << ans.size();
    } else {

        int MAX = 5000, cnt = 0;

        FOR (i, 1, MAX) {
            if (!freq[i]) continue;

            FOR (j, i, MAX) {
                if (!freq[j]) continue;

                int sum = i + j;

                if (sum % 2 == 0) {
                    int avg = sum / 2;
                    cnt += 1;
                }
            }
        }
        cout << cnt;
    }

    return 0;
}

