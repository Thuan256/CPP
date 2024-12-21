#include <iostream>
#include <vector>

#define f first
#define s second

using namespace std;

class solution {
  public:
    void solve() {
        int n;
        vector<int> a;
        cin >> n;
        a.resize(n);

        int nmax = -1e6;
        for (auto &p : a) {
            cin >> p;
            if (p < 0)
                nmax = max(nmax, p);
        }

        cout << (nmax == -1e6 ? 0 : nmax);
    }
};

int main() {

    freopen("soam.inp", "r", stdin);
    freopen("soam.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution Sol;
    Sol.solve();

    return 0;
}
