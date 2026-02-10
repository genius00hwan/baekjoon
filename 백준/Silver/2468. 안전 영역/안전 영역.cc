//
// Created by 김수환 on 2022/08/21.
//
#include <iostream>
#include <queue>

using namespace std;

int n, top, rain, cnt, ans;
int land[101][101];
bool safe[101][101];
bool visited[101][101];
int xDir[4] = {0, 1, 0, -1};
int yDir[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nextX = x + xDir[i];
        int nextY = y + yDir[i];
        if (visited[nextX][nextY] || !safe[nextX][nextY]) continue;
        if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n)
            dfs(nextX, nextY);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> land[i][j];
            if (land[i][j] > top)
                top = land[i][j];
        }
    }
    for (rain = 0; rain <= top; rain++) {//비 안올때 부터 다잠길 때 까지
        cnt = 0;
        for (int i = 0; i < n; i++) {//초기화
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
                safe[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                safe[i][j] = (land[i][j] > rain);//강수량 보다 높은 땅이면 안전 지대
        }
        for (int i = 0; i < n; i++) {//안전영역 세기
            for (int j = 0; j < n; j++) {
                if (safe[i][j] && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        if (ans < cnt)
            ans = cnt;
    }
    cout << ans;
    return 0;
}