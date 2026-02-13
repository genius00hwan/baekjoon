#include <bits/stdc++.h>

#define SZ 10
#define MAX 26

using namespace std;

bool board[SZ][SZ];
int papers[6];
int ans = MAX;
int oneCnt;

//void debug(int r, int c, int s) {
//    cout << "cur: {" << r << ", " << c << "} size:" << s;
//    cout << endl;
//    for (int i = 0; i < SZ; i++) {
//        for (int j = 0; j < SZ; j++) {
//            cout << board[i][j] << ' ';
//        }
//        cout << endl;
//    }
//}


int next(int startPos) {
    for (int pos = startPos; pos < SZ * SZ; pos++) {
        int r = pos / SZ, c = pos % SZ;
        if (board[r][c] == 1) return pos;
    }
    return -1;
}

bool mayI(int r, int c, int sz) {
    if (r + sz > SZ || c + sz > SZ) return false;
    for (int i = r; i < r + sz; i++) {
        for (int j = c; j < c + sz; j++) {
            if (board[i][j] != 1) return false;
        }
    }
    return true;
}

void commit(int r, int c, int sz) {
    for (int i = r; i < r + sz; i++)
        for (int j = c; j < c + sz; j++)board[i][j] = false;
}

void rollback(int r, int c, int sz) {
    for (int i = r; i < r + sz; i++)
        for (int j = c; j < c + sz; j++) board[i][j] = true;
}

void dfs(int cur, int used, int remain) {
    if (used >= ans) return;
    if (remain == 0) {
        ans = min(ans, used);
        return;
    }

    int pos = next(cur);
    if (pos == -1) return;

    int r = pos / 10, c = pos % 10;

    for (int s = 5; s >= 1; s--) {
        if (papers[s] == 0) continue;
        if (!mayI(r, c, s)) continue;

        papers[s]--;
        commit(r, c, s);
//        debug(r, c, s);
        dfs(pos + 1, used + 1, remain - (s * s));

        rollback(r, c, s);
        papers[s]++;
    }
}

void init() {
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            cin >> board[i][j];
            if (board[i][j]) oneCnt++;
        }
    }

    fill(&papers[0], &papers[6], 5);

}

void solve() {
    dfs(0, 0, oneCnt);

    cout << (ans == 26 ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    solve();

    return 0;
}
