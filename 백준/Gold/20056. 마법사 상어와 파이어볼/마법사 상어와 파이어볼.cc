#include <bits/stdc++.h>

using namespace std;

#define MAX 51

int N, M, K;
int rd[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int cd[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int mod(int x) {
    int y = x % N;
    return y < 0 ? y + N : y;
}

struct fb {
    int dir;
    int mass;
    int speed;
};


struct node {
    queue<fb> readyQ;
    vector<fb> arrived;
};

node graph[MAX][MAX];

void shoot(int r, int c) {
    node *node = &graph[r][c];
    while (!node->readyQ.empty()) {
        fb cur = node->readyQ.front();
        node->readyQ.pop();
        int nr = mod(r + (rd[cur.dir] * cur.speed));
        int nc = mod(c + (cd[cur.dir] * cur.speed));
        graph[nr][nc].arrived.push_back(cur);
    }
}

void split(int r, int c) {
    node *node = &graph[r][c];
    if (node->arrived.empty())return;
    if (node->arrived.size() == 1) {
        node->readyQ.push(graph[r][c].arrived[0]);
        node->arrived.clear();
        return;
    }
    int m = 0;
    int s = 0;
    bool flag = node->arrived[0].dir % 2;
    int dir = 0;
    for (fb cur: node->arrived) {
        m += cur.mass;
        s += cur.speed;
        dir = dir|(flag ^ (cur.dir % 2));
    }
    m /= 5;
    s /= node->arrived.size();
    node->arrived.clear();
    if (!m)return;

    for (int d = dir; d < 8; d += 2) {
        node->readyQ.push({d, m, s});
    }
}
//void debug() {
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cout<<'{';
//            for(fb cur : graph[i][j].arrived){
//                cout << '(' << cur.mass << "," << cur.speed << ',' << cur.dir << "),";
//            }
//            cout <<"} ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

int count() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            while (!graph[i][j].readyQ.empty()) {
                ret += graph[i][j].readyQ.front().mass;
                graph[i][j].readyQ.pop();
            }
        }
    }
    return ret;
}

void init() {
    cin >> N >> M >> K;
    while (M--) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        graph[r - 1][c - 1].readyQ.push({d, m, s});
    }
}

void solve() {
    while (K--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                shoot(i, j);
            }
        }
//    debug();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                split(i, j);
            }
        }
    }
    cout << count();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();
}