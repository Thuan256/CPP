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

int n, d;
vi a;
int leftAns, rightAns;

bool check(double x) {
    double p[n];
    vector<pair<double, double>> mn(n);
    mn[0].ff = a[0]-x; mn[0].ss = 0;
    p[0] = a[0]-x;
    bool flag = 0;
    double cur_sum = p[0];
    fto(i, 1, n-1) {
        cur_sum += (a[i]-x);
        p[i] = cur_sum;
        if (p[i] <= mn[i-1].ff) {
            mn[i].ff = cur_sum;
            mn[i].ss = i;
        } else {
            mn[i].ff = mn[i-1].ff;
            mn[i].ss = mn[i-1].ss;
        }
    }
    for (int i=n-1; i+1-d >= 0; i--) {
        if (i+1-d >= 0 && p[i]>=0) {
            leftAns = 0;
            rightAns = i;
            flag = 1;
            break;
        }
        if (mn[i-d].first <= p[i]) {
            leftAns = mn[i-d].ss+1;
            rightAns = i;
            flag = 1;
            break;
        }
    }
    return flag;
}
int main() {
    fastio;
    cin >> n >> d;
    a.resize(n);
    fto(i, 0, n-1) {
        cin >> a[i];
    }
    double low = 0, high = 110;
    fto(i, 0, 109) {
        double mid = (low + high)/2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    double s = 0.0;
    fto(i, leftAns, rightAns) s += a[i];
    cout << setprecision(5) << fixed << s/(rightAns-leftAns+1) << "\n";
    return 0;
}
