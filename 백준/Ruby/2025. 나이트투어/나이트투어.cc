#include <bits/stdc++.h>


using namespace std;
typedef long long LL;

int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

int n;
int br, bc;

vector<vector<int>> board;
vector<pair<int, int>> path;

bool oob(int r, int c) {
    return r < 0 || c < 0 || r >= n || c >= n;
}

int getDegree(int r, int c) {
    int cnt = 0;
    for (int d = 0; d < 8; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (!oob(nr, nc) && board[nr][nc] == -1) cnt++;
    }
    return cnt;
}

int getDegreeBlocked(int r, int c, int br, int bc) {
    int cnt = 0;
    for (int d = 0; d < 8; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (oob(nr, nc)) continue;
        if (board[nr][nc] != -1) continue;
        if (nr == br && nc == bc) continue;
        cnt++;
    }
    return cnt;
}

LL centerDist2(int r, int c) {
    LL cr = n - 1;
    LL cc = n - 1;
    LL pr = 2LL * r;
    LL pc = 2LL * c;
    LL dr = pr - cr;
    LL dc = pc - cc;
    return dr * dr + dc * dc;
}

pair<int, int> getLookAhead(int nr, int nc, int r, int c) {
    int nextMin = 9;
    int nextSum = 0;

    for (int dd = 0; dd < 8; dd++) {
        int tr = nr + dr[dd];
        int tc = nc + dc[dd];
        if (oob(tr, tc) || board[tr][tc] != -1) continue;
        if (tr == r && tc == c) continue;

        int v = getDegreeBlocked(tr, tc, nr, nc);
        nextMin = min(nextMin, v);
        nextSum += v;
    }

    if (nextMin == 9) nextMin = -1;
    return {nextMin, nextSum};
}

bool betterLookAhead(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

bool knightTour(int sr, int sc, int rot, bool rev) {
    board.assign(n, vector<int>(n, -1));
    path.clear();

    vector<int> ord(8);
    iota(ord.begin(), ord.end(), 0);
    rotate(ord.begin(), ord.begin() + rot, ord.end());
    if (rev) reverse(ord.begin(), ord.end());

    int r = sr, c = sc;
    board[r][c] = 0;
    path.emplace_back(r, c);

    for (int step = 1; step < n * n; step++) {
        int bestR = -1;
        int bestC = -1;
        int bestDeg = 9;
        LL bestDist = -1;
        pair<int, int> bestLook = {10, 10};
        bool bestLookReady = false;

        for (int idx = 0; idx < 8; idx++) {
            int d = ord[idx];
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (oob(nr, nc) || board[nr][nc] != -1) continue;

            int deg = getDegree(nr, nc);
            LL dist = centerDist2(nr, nc);

            if (deg < bestDeg) {
                bestR = nr;
                bestC = nc;
                bestDeg = deg;
                bestDist = dist;
                bestLookReady = false;
                continue;
            }

            if (deg > bestDeg) continue;

            if (dist > bestDist) {
                bestR = nr;
                bestC = nc;
                bestDist = dist;
                bestLookReady = false;
                continue;
            }

            if (dist < bestDist) continue;

            pair<int, int> candLook = getLookAhead(nr, nc, r, c);

            if (!bestLookReady) {
                bestLook = getLookAhead(bestR, bestC, r, c);
                bestLookReady = true;
            }

            if (betterLookAhead(candLook, bestLook)) {
                bestR = nr;
                bestC = nc;
                bestLook = candLook;
                bestLookReady = true;
            } else if (candLook == bestLook) {
                if (nr < bestR || (nr == bestR && nc < bestC)) {
                    bestR = nr;
                    bestC = nc;
                    bestLook = candLook;
                    bestLookReady = true;
                }
            }
        }

        if (bestR == -1) return false;

        r = bestR;
        c = bestC;
        board[r][c] = step;
        path.emplace_back(r, c);
    }

    return true;
}

void init() {
    cin >> n >> br >> bc;
    br--;
    bc--;
}

void solve() {
    for (int rot = 0; rot < 8; rot++) {
        if (knightTour(br, bc, rot, false)) {
            for (auto p : path) {
                cout << p.first + 1 << ' ' << p.second + 1 << '\n';
            }
            return;
        }
        if (knightTour(br, bc, rot, true)) {
            for (auto p : path) {
                cout << p.first + 1 << ' ' << p.second + 1 << '\n';
            }
            return;
        }
    }

    cout << "-1 -1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}