#include <iostream>
#include <queue>

#define INF 40001

using namespace std;


int dc[12] = {0, 0, -1, 1, -2, -1, 1, 2, -2, -1, 1, 2};
int dr[12] = {1, -1, 0, 0, 1, 2, 2, 1, -1, -2, -2, -1};

int k, w, h;

int cost[201][201][31];// 거리, 기술 쓴 회수
int graph[201][201];

struct tmp {
    int c;
    int r;
    int cnt;
};

void bfs() {
    queue<tmp> q;
    q.push({0, 0, 0});
    cost[0][0][0] = 0;
    while (!q.empty()) {
        int curC = q.front().c;
        int curR = q.front().r;
        int curCnt = q.front().cnt;
        q.pop();
//        cout << "cur ";
//        cout << curC << ',' << curR << ':' << curCnt << '\n'; //debug
//        cout << "next " << '\n';
        for (int i = 0; i < 12; i++) {
            int nextC = curC + dc[i];
            int nextR = curR + dr[i];
            int nextCnt = (i < 4) ? curCnt : curCnt + 1;
//            cout << nextC << ',' << nextR << ':' << endl;// debug
            if (nextCnt > k) continue;
            if (nextC < 0 || nextC >= h || nextR < 0 || nextR >= w)continue;
            if (graph[nextC][nextR] == 1) continue;
            if (cost[nextC][nextR][nextCnt] <= cost[curC][curR][curCnt] + 1)
                continue;
            cost[nextC][nextR][nextCnt] = cost[curC][curR][curCnt] + 1;
            q.push({nextC, nextR, nextCnt});
//            cout << cost[nextC][nextR][nextCnt] << '/' << nextCnt << '\n'; //debug
        }
    }
}

void init() {
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> graph[i][j];
            for (int l = 0; l <= k; l++) {
                cost[i][j][l] = INF;
            }
        }
    }

}

void solve() {
    bfs();
    int ans = INF;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, cost[h - 1][w - 1][i]);
    }
    ans == INF ? cout << -1 : cout << ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();

    return 0;
}
