#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll count_missing(const vector<ll>& A, ll x) {
    return x - (lower_bound(A.begin(), A.end(), x + 1) - A.begin());
}

ll find_kth_missing(const vector<ll>& A, ll k) {
    ll left = 1, right = 1e18, result = -1;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (count_missing(A, mid) >= k) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    ifstream inp("SOK.INP");
    ofstream out("SOK.OUT");

    ll n, t;
    inp >> n >> t;

    vector<ll> A(n);
    for (ll i = 0; i < n; ++i) {
        inp >> A[i];
    }

    sort(A.begin(), A.end());

    while (t--) {
        ll k;
        inp >> k;
        out << find_kth_missing(A, k) << "\n";
    }

    inp.close();
    out.close();

    return 0;
}
