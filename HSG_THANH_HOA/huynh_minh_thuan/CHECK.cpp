#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[100001];
vector<int> b, tmp;
unordered_set<int> c;

void backtrack(int s, vector<int> cur) {

    ll sum = 0;

    if (cur.size()) {
        for (int x: cur) sum += x;
        c.insert(sum);
    }

    for (int i = s; i < b.size(); i ++) {
        if (i > s && b[i] == b[i - 1]) continue;

        cur.push_back(b[i]);

        backtrack(i + 1, cur);

        cur.pop_back();
    }
}

int main() {
    ifstream inp("CHECK.inp");
    ofstream out("CHECK.out");

    int n, m, i, ans = 0;
    inp >> n >> m;
    b.resize(m);

    for (i = 0; i < n; i++) inp >> a[i];
    for (i = 0; i < m; i++) inp >> b[i];

    sort(b.begin(), b.end());

    backtrack(0, tmp);

    for (int x: a) ans += (c.find(x) != c.end());

    out << ans;

    inp.close();
    out.close();

    return 0;
}
