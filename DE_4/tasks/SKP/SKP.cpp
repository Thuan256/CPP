#include<bits/stdc++.h>
using namespace std;

//---------------------------- Define containers ----------------------------//
#define ll long long

const int N = 1e6;
const int M = 1 << 21;
const ll oo = 1e18;

//------------------------- Define builtin functions -------------------------//
#define nl '\n'
#define debug(x) cout << #x << " : " << x << nl;

// loops
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
//------------------------- Solution -------------------------//

int n;
ll b[N], h[N], f[N];

void subtask1(){
    h[0] = oo;
    b[0] = 0;
    fill(f + 1, f + n + 1, -oo);
    FOR(i, 1, n){
        int mn = 0;
        ROF(j, i, 1){
            mn = (h[mn] < h[j]) ? mn : j;
            f[i] = max(f[i], f[j-1] + b[mn]);
        }
    }
}

ll st[M], lazy[M];

void down(int idx){
    ll tmp = lazy[idx];
    if(tmp == 0) return;

    st[idx<<1] += tmp;
    lazy[idx<<1] += tmp;

    st[idx<<1|1] += tmp;
    lazy[idx<<1|1] += tmp;

    lazy[idx] = 0;
}

void update(int idx, int lx, int rx, int l, int r, ll x){
    if(lx > r || rx < l) return;
    if(lx >= l && rx <= r){
        if(st[idx] == -oo) st[idx] = x;
        else st[idx] += x;
        lazy[idx] += x;
        return;
    }
    down(idx);
    int mid = (lx + rx)/2;
    update(2*idx, lx, mid, l, r, x);
    update(2*idx + 1, mid + 1, rx, l, r, x);
    st[idx] = max(st[idx<<1], st[idx<<1|1]);
}

void update_point(int idx, int lx, int rx, int pos, ll x){
    if(lx == rx){
        st[idx] = x;
        lazy[idx] = x;
        return;
    }
    down(idx);
    int mid = (lx + rx)/2;
    if(pos <= mid) update_point(2*idx, lx, mid, pos, x);
    else update_point(2*idx + 1, mid + 1, rx, pos, x);
    st[idx] = max(st[idx<<1], st[idx<<1|1]);
}

ll query(int idx, int lx, int rx, int l, int r){
    if(lx > r || rx < l) return -oo;
    if(lx >= l && rx <= r) return st[idx];
    down(idx);
    int mid = (lx + rx)/2;
    return max(query(2*idx, lx, mid, l, r),
                    query(2*idx + 1, mid + 1, rx, l, r));
}

void subtask2(){
    stack<int> q;
    h[0] = -oo;
    fill(st + 0, st + M, -oo);
    q.push(0);
    FOR(i, 1, n){
        while(!q.empty() && h[q.top()] >= h[i]){
            int id = q.top();
            q.pop();
            update(1, 0, n, q.top(), id - 1, -b[id]);
        }
        update(1, 0, n, q.top(), i-1, b[i]);
        f[i] = st[1];
        update_point(1, 0, n, i, f[i]);
        q.push(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SKP.INP", "r", stdin);
    freopen("SKP.OUT", "w", stdout);
    cin >> n;
    FOR(i, 1, n) cin >> h[i];
    FOR(i, 1, n) cin >> b[i];

    if(n <= 1000) subtask1();
    else subtask2();

    cout << f[n];
}
