#include <iostream>

#define MAX 47000

using namespace std;

int t, x, y;
long long d;
long long arr[MAX + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (long long i = 1; i <= MAX; i++) {
        arr[i] = (i * i + i);
    }
    cin >> t;
    while (t--) {
        cin >> x >> y;
        d = y - x;
        if (d == 1) {
            cout << 1 << "\n";
            continue;
        }
        for (long long i = 1; i <= MAX; i++) {
            if (d > arr[i - 1] && d <= arr[i]) {
                if (d <= i * i) cout << 2 * i - 1 << '\n';
                else cout << 2 * i << '\n';
                break;
            }
        }
    }

    return 0;
}