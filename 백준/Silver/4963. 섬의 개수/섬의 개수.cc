#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
queue<pair<int, int>> q;
int map[50][50];
int visited[50][50];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int w, h;

void bfs() {
    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nextY = cur_y + dy[i];
            int nextX = cur_x + dx[i];
            if (!map[nextY][nextX] || visited[nextY][nextX])continue;
            if (nextX >= 0 && nextX < w && nextY >= 0 && nextY < h) {
                visited[nextY][nextX] = true;
                q.push({nextY, nextX});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (1) {
        int cnt = 0;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j] && map[i][j]) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    bfs();
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                map[i][j] = false;
                visited[i][j] = false;
            }
        }
    }
}