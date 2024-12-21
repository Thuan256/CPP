#include <iostream>
#include <vector>

#define f first
#define s second

using namespace std;

class solution {
  public:
    int dao(int &x) {
        int y = 0;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }

        return y;
    }
    void solve() {
        int x;
        cin >> x;

        cout << dao(x) % 19;
    }
};

int main() {

    freopen("sodao.inp", "r", stdin);
    freopen("sodao.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution Sol;
    Sol.solve();

    return 0;
}
