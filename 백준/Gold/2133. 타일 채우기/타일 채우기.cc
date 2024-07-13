#include <bits/stdc++.h>

using namespace std;

int n;
int mem[17];

void init() {
    cin >> n;
    mem[0] = 3;
}

void solve() {
    if (n % 2) {
        cout << 0;
        return;
    }
    n /= 2;
    for (int i = 1; i < 15; i++) {
        mem[i] += mem[i - 1] * 3;
        for (int j = i - 2; j >= 0; j--) {
            mem[i] += mem[j] * 2;
        }
        mem[i] += 2;
    }
    cout << mem[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();
}