#include <bits/stdc++.h>

using namespace std;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K;

struct fire {
    int m;
    int s;
    int d;
};
int ans;

struct node {
    queue<fire> sq;
    queue<fire> dq;
};
node graph[52][52];

void init() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        graph[r - 1][c - 1].sq.push({m, s, d});
    }
}

void shoot(int r, int c) {
    while (!graph[r][c].sq.empty()) {
        fire f = graph[r][c].sq.front();
        graph[r][c].sq.pop();
        int nr = r + dr[f.d] * f.s;
        while (nr < 0) {
            nr += N;
        }
        nr %= N;

        int nc = c + dc[f.d] * f.s;
        while (nc < 0) {
            nc += N;
        }
        nc %= N;

        graph[nr][nc].dq.push(f);
    }
}

void sumAndDiv(int r, int c) {
    if (graph[r][c].dq.empty())return;
    if (graph[r][c].dq.size() == 1) {
        graph[r][c].sq.push(graph[r][c].dq.front());
        graph[r][c].dq.pop();
        return;
    }
    int fn = graph[r][c].dq.size();
    fire f = graph[r][c].dq.front();
    graph[r][c].dq.pop();
    int flag = f.d % 2;
    while (!graph[r][c].dq.empty()) {
        f.m += graph[r][c].dq.front().m;
        f.s += graph[r][c].dq.front().s;
        if (flag != graph[r][c].dq.front().d % 2)
            flag = 2;
        graph[r][c].dq.pop();
    }
    if (!(f.m / 5) || !(f.s / fn))
        return;
    if (flag == 2) {
        for (int i = 0; i < 4; i++) {
            graph[r][c].sq.push({f.m / 5, f.s / fn, 2 * i + 1});
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        graph[r][c].sq.push({f.m / 5, f.s / fn, 2 * i});
    }

}


void solve() {
    while (K--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                shoot(i, j);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sumAndDiv(i, j);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            while (!graph[i][j].sq.empty()) {
                ans += graph[i][j].sq.front().m;
                graph[i][j].sq.pop();
            }
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}