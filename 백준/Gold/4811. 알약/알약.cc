#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> cmd;
string ans;
ll mem[31][31];

ll dp(int w, int h) {
    if (w == 0) return 1;
    if (mem[w][h] != -1) return mem[w][h];

    mem[w][h] = 0;
    if (w > 0) mem[w][h] += dp(w - 1, h + 1);
    if (h > 0) mem[w][h] += dp(w, h - 1);

    return mem[w][h];
}

void init() {
    memset(mem, -1, sizeof(mem));
    while (true) {
        int n;
        cin >> n;
        if (!n) break;
        cmd.emplace_back(n);
    }
}

void solve() {
    for (int i = 0; i < cmd.size(); i++) {
        ans += to_string(dp(cmd[i], 0));
        if (i == cmd.size() - 1)break;
        ans += '\n';
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();

    return 0;
}
