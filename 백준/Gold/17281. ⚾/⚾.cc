#include <bits/stdc++.h>
using namespace std;

static const int PLAYER_SIZE = 9;
int n;
int power[51][9];

bool used[9];
int order[9];
int ans = 0;

void play() {
    int score = 0;
    int cur = 0;

    for (int inning = 0; inning < n; inning++) {
        int outs = 0;
        bool b1 = false, b2 = false, b3 = false;

        while (outs < 3) {
            int player = order[cur];
            int hit = power[inning][player];

            if (hit == 0) {
                outs++;
            } else if (hit == 1) {
                if (b3) score++;
                b3 = b2;
                b2 = b1;
                b1 = true;
            } else if (hit == 2) {
                if (b3) score++;
                if (b2) score++;
                b3 = b1;
                b2 = true;
                b1 = false;
            } else if (hit == 3) {
                if (b3) score++;
                if (b2) score++;
                if (b1) score++;
                b3 = true;
                b2 = false;
                b1 = false;
            } else {
                if (b3) score++;
                if (b2) score++;
                if (b1) score++;
                score++;
                b1 = b2 = b3 = false;
            }

            cur = (cur + 1) % PLAYER_SIZE;
        }
    }

    ans = max(ans, score);
}

void dfs(int pos) {
    if (pos == PLAYER_SIZE) {
        play();
        return;
    }
    if (pos == 3) {
        dfs(pos + 1);
        return;
    }

    for (int p = 1; p < PLAYER_SIZE; p++) {
        if (used[p]) continue;
        used[p] = true;
        order[pos] = p;
        dfs(pos + 1);
        used[p] = false;
    }
}

void init(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int p = 0; p < 9; p++) cin >> power[i][p];
    }
}

void solve(){
    memset(used, 0, sizeof(used));
    used[0] = true;
    order[3] = 0;
    dfs(0);

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();

    return 0;
}
