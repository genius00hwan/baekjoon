#include <bits/stdc++.h>

using namespace std;

int N;
int board[8][8];

int mx = 100;
void init() {
    cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> board[r][c];
        }
    }
}

void dfs(int idx, int cnt) {
    if (cnt == N || idx == 2 * N) {
        int w = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                w += board[r][c];
            }
        }
        mx = min(mx, cnt + min(w, N * N - w));
        return;
    }

    dfs(idx + 1, cnt);
    if (idx < N) {
        for (int r = 0; r < N; r++) {
            board[r][idx] ^= 1;
        }
        dfs(idx + 1, cnt + 1);
        for (int r = 0; r < N; r++) {
            board[r][idx] ^= 1;
        }
    }
    else {
        for (int c = 0; c < N; c++) {
            board[idx - N][c] ^= 1;
        }
        dfs(idx + 1, cnt + 1);
        for (int c = 0; c < N; c++) {
            board[idx - N][c] ^= 1;
        }
    }
}

void solve() {
    dfs(0, 0);

    cout << mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    solve();

}
