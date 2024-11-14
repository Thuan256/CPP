#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    int order;
    int count = 1;
    int max_val = 0;
    int last_num;

    int a[n];

    for (int i = 0; i < n; i++) {
        int num;
        cout << "A[" << i << "] = ";
        cin >> num;

        if (i) {
            max_val = max(count, max_val);

            if (num == last_num) {
                count = 1;
                order = !order;
            } else if ((order && num > last_num) || (!order && num < last_num))
                count += 1;
            else {
                count = 2;
                order = !order;
            }
        };
        last_num = num;
        if (i == 1) order = num > last_num;
    }

    cout << max(count, max_val);
}