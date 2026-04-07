#include <bits/stdc++.h>

using namespace std;

int n;
int board[17][17];
long long mem[17][17][3];

bool check(int x, int y) {
    if (x + 1 > n || y + 1 > n) return false;
    if (board[x][y + 1]) return false;
    if (board[x + 1][y]) return false;
    if (board[x + 1][y + 1]) return false;
    return true;
}

long long dp(int x, int y, int dir) {
    if (x == n && y == n) return 1;

    if (mem[x][y][dir] != -1) return mem[x][y][dir];

    mem[x][y][dir] = 0;

    if (dir == 0) { // -> 오른쪽
        if (y + 1 <= n && board[x][y + 1] == 0) {
            mem[x][y][dir] += dp(x, y + 1, 0);
        }
        if (check(x, y)) {
            mem[x][y][dir] += dp(x + 1, y + 1, 2);
        }
        return mem[x][y][dir];
    }
    if (dir == 1) { // V 아래로
        if (x + 1 <= n && board[x + 1][y] == 0) {
            mem[x][y][dir] += dp(x + 1, y, 1);
        }
        if (check(x, y)) {
            mem[x][y][dir] += dp(x + 1, y + 1, 2);
        }
        return mem[x][y][dir];
    }

    // L> 우하단
    if (y + 1 <= n && board[x][y + 1] == 0) {
        mem[x][y][dir] += dp(x, y + 1, 0);
    }
    if (x + 1 <= n && board[x + 1][y] == 0) {
        mem[x][y][dir] += dp(x + 1, y, 1);
    }
    if (check(x, y)) {
        mem[x][y][dir] += dp(x + 1, y + 1, 2);
    }
    return mem[x][y][dir];


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    memset(mem, -1, sizeof(mem));

    cout << dp(1, 2, 0) << '\n';
    return 0;
}