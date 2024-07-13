#include <bits/stdc++.h>

#define INF 987654321
using namespace std;
int n;
int stat[22][22];
bool team[11];
int ans;

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> stat[i][j];
        }
    }
    ans = INF;
}

void dfs(int idx, int num) {
    if (idx >= n) return;
    if (num == n / 2) {
        int t0 = 0;
        int t1 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (team[i] && team[j]) t0 += stat[i][j];
                if (!team[i] && !team[j]) t1 += stat[i][j];
            }
        }
        ans = min(ans, abs(t0 - t1));
        return;
    }
    team[idx] = true;
    dfs(idx + 1, num + 1);
    team[idx] = false;
    dfs(idx + 1, num);
}

void solve() {
    dfs(0, 0);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}