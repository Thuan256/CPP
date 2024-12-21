#include <iostream>
#include <vector>

#define f first
#define s second

using namespace std;

class solution {
  public:
    void solve() {
        int n, d, w;
        long long s = 0;
        cin >> n >> d;
        char h;

        while (n--) {
            cin >> h >> w;
            s += w * d;
        }

        cout << s;
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
