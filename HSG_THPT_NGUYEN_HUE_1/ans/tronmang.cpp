#include <cstdio>
#include <iostream>
#include <vector>

#define f first
#define s second
#define vi vector<int>

using namespace std;

class solution {
  public:
    vi tron(vi &a, vi &b) {
        vi c;

        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
            c.push_back((a[i] <= b[j] ? a[i++] : b[j++]));
        while (i < a.size())
            c.push_back(a[i++]);

        while (j < b.size())
            c.push_back(b[j++]);

        return c;
    }

    void solve() {
        int n, m;
        cin >> n >> m;
        vi a(n), b(m);
        for (auto &p : a)
            cin >> p;
        for (auto &p : b)
            cin >> p;

        for (auto &p : tron(a, b))
            cout << p << '\n';
    }
};

int main() {

    freopen("b.inp", "r", stdin);
    freopen("b.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution Sol;
    Sol.solve();

    return 0;
}
