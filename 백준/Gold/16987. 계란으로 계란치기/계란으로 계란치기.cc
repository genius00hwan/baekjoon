#include <bits/stdc++.h>
using namespace std;

struct Egg {
    int s; // durability (내구도)
    int w; // weight (무게)
};

int n, ans = 0;
vector<Egg> eggs;

void init() {
    cin >> n;
    eggs.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> eggs[i].s >> eggs[i].w; // s, w 입력 그대로
    }
}

void commit(int a, int b) {
    int wa = eggs[a].w;
    int wb = eggs[b].w;
    eggs[a].s -= wb;
    eggs[b].s -= wa;
}

void rollback(int a, int b) {
    int wa = eggs[a].w;
    int wb = eggs[b].w;
    eggs[a].s += wb;
    eggs[b].s += wa;
}

void dfs(int idx, int cnt) {
    ans = max(ans, cnt);
    if (idx == n) return;

    if (eggs[idx].s <= 0) {
        dfs(idx + 1, cnt);
        return;
    }

    bool flag = false;

    for (int j = 0; j < n; j++) {
        if (j == idx) continue;
        if (eggs[j].s <= 0) continue;

        flag = true;

        commit(idx, j);

        int add = 0;
        if (eggs[idx].s <= 0) add++;
        if (eggs[j].s <= 0) add++;

        dfs(idx + 1, cnt + add);

        rollback(idx, j);
    }

    if (!flag) {
        dfs(idx + 1, cnt);
    }
}

void solve() {
    dfs(0, 0);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
    return 0;
}
