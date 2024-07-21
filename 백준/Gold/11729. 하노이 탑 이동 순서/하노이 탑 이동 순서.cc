#include <bits/stdc++.h>

using namespace std;

int n;
int cnt;

void init() {
    cin >> n;
}

void solve(int c, int s, int d) {
    if (c == 1) {
        cout << s << " " << d;
        cnt++;
        if (cnt < pow(2, n) - 1) {
            cout << '\n';
        }
        return;
    }
    solve(c - 1, s, 6 - s - d);
    cout << s << " " << d << '\n';
    cnt++;
    solve(c - 1, 6 - s - d, d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    long long ans = pow(2,n)-1;
    cout << ans << "\n";
    solve(n, 1, 3);
}