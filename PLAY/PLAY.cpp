#include <bits/stdc++.h>

using namespace std;

int main() {

    ifstream inp("PLAY.inp");
    ofstream out("PLAY.out");

    int n;
    inp >> n;
    int a[n], ans = 0;

    for (int i = 0; i < n; i++) inp >> a[i];

    auto next = [&](int x) {
        return x + 1 == n ? 0 : x + 1;
    };

    auto prev = [&](int x) {
        return x - 1 < 0 ? n - 1 : x - 1;
    };

    for (int i = 0; i < n; i++) {
        int point[2] = {0, 0};
        int turn = 0;

        point[0] += (a[i] % 2 != 0);

        int left = prev(i);
        int right = next(i);

        while (right - left + 1 < n && abs(right - left) != 0) {

            if (a[left] % 2 != 0) {
                point[turn]++;
                left = prev(left);
            } else {
                if (a[right] % 2 != 0) point[turn]++;
                right = next(right);
            }

            turn = !turn;
        }

        ans += (point[0] > point[1]);
    }

    out << ans;
    out.close();
    inp.close();
}
