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

using namespace std;

int n, m, cnt, tmin = oo, ans;
vector <pair<int, int>> g[maxN];
int f[3][maxN];

void shortest(int id, int s) {
    fto(u, 1, n) f[id][u] = oo;
    f[id][s] = 0;
    priority_queue< ii, vii, greater<ii> > pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u, r;
        tie(r, u) = pq.top();
        pq.pop();
        for (pair <int, int> c : g[u]) {
            int v = c.ff;
            int w = c.ss;
            if (f[id][u] + w < f[id][v]) f[id][v] = f[id][u] + w, pq.push({f[id][v], v});
        }
    }
}

int main() {
    cin >> n >> m;
    fto(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    shortest(2, n);
    shortest(1, 1);
    fto(u, 1, n) {
        tmin = min(tmin, f[1][u] + f[2][u]);
    }
    fto(u, 1, n) {
        if (f[1][u] + f[2][u] == tmin) ans++;
    }
    cout << ans << endl;
    return 0;
}