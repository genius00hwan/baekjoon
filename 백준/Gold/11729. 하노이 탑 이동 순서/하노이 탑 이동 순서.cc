#include <bits/stdc++.h>

using namespace std;

int n;

void init() {
    cin >> n;
}

void solve(int c, int s, int d) {
    if (c == 1) {
        cout << s << " " << d << '\n';
        return;
    }
    solve(c - 1, s, 6 - s - d);
    cout << s << " " << d << '\n';
    solve(c - 1, 6 - s - d, d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    cout << (1 << n) - 1 << "\n";
    solve(n, 1, 3);
}