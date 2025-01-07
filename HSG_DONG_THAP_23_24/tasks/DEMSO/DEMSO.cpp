#include <bits/stdc++.h>

using namespace std;

#define oo 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define bug(a) cout << #a << ": " << a << endl
#define bug2(a, b) cout << #a << ": " << a << "; " << #b << ": " << b << endl
#define bugarr(a, i, j) cout << #a << "[" << i << ".." << j << "]: "; for(int k = i; k < j; ++k) cout << a[k] << ", "; cout << a[j] << endl;
#define fto(i, x, y) for (int i = (int)(x); i <= (int)(y); ++i)
#define fdto(i, x, y) for (int i = (int)(x); i >= (int)(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d ", a)
#define pril(a) printf("%d\n", a)
#define maxN 100005

int main() {
	fastio;

    ll m, n; cin >> m >> n;
    int q; cin >> q;
    while (q--) {
    	ll x; cin >> x;
    	int cnt = 0;
    	fto(i, 1, m) {
    		if (x%i == 0LL && x/i <= n) ++cnt;
    	}
    	cout << cnt << "\n";
    }

	return 0;
}

