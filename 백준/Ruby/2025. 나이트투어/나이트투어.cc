#include <bits/stdc++.h>


using namespace std;

const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n;
vector<vector<int>> board;
vector<pair<int, int>> path;

int getDegree(int x, int y) {
    int cnt = 0;
    for (int d = 0; d < 8; ++d) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && board[nx][ny] == -1)
            ++cnt;
    }
    return cnt;
}

bool knightTour(int x, int y) {
    board.assign(n, vector<int>(n, -1));
    path.clear();

    board[x][y] = 0;
    path.emplace_back(x, y);

    for (int step = 1; step < n * n; ++step) {
        int minDegree = 9, nextX = -1, nextY = -1;

        for (int d = 0; d < 8; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && board[nx][ny] == -1) {
                int deg = getDegree(nx, ny);
                if (deg < minDegree) {
                    minDegree = deg;
                    nextX = nx;
                    nextY = ny;
                }
            }
        }

        if (nextX == -1) return false;

        board[nextX][nextY] = step;
        path.emplace_back(nextX, nextY);
        x = nextX;
        y = nextY;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> n >> x >> y;
    --x; --y;

    if (!knightTour(x, y)) {
        cout << "-1 -1\n";
        return 0;
    }

    for (const auto& [i, j] : path) {
        cout << i + 1 << " " << j + 1 << "\n";
    }
}