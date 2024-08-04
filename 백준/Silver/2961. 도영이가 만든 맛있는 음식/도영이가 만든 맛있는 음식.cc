#include <bits/stdc++.h>

using namespace std;

int taste[11][2];
int n;
int ans = INT_MAX;

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> taste[i][0] >> taste[i][1];
    }
}

void bt(int idx, int sour, int bitter, int cnt) {
    if (idx == n) {
        if (cnt) ans = min(ans, abs(sour - bitter));
        return;
    }
    bt(idx + 1, sour * taste[idx][0], bitter + taste[idx][1], cnt+1);
    bt(idx + 1, sour, bitter, cnt);

}

void solve() {
    bt(0, 1, 0, 0);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();
    return 0;
}
