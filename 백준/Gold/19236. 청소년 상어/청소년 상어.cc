#include <bits/stdc++.h>

#define N 16
#define L 4


using namespace std;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct fish {
    int r;
    int c;
    int d;
    bool alive;
};

fish fishes[N];
int graph[L][L]; // 물고기 번호만 저장
int ans;
fish shk;

void init() {
    int a, b;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            cin >> a >> b;
            fishes[a - 1] = {i, j, b - 1, true};
            graph[i][j] = a - 1;
        }
    }
}

bool outOfBound(int r, int c) {
    return (r < 0 || r >= L || c < 0 || c >= L);
}

void fishMove() {
    for (int i = 0; i < N; i++) {
        if (!fishes[i].alive)continue;
        int nr, nc;
        for (int j = 0; j < 8; j++) {
            nr = fishes[i].r + dr[fishes[i].d];
            nc = fishes[i].c + dc[fishes[i].d];
            if (outOfBound(nr, nc)||graph[nr][nc]==-2){
                fishes[i].d = (fishes[i].d + 1) % 8;
                continue;
            }
            break;
        }
        if (fishes[i].r == nr && fishes[i].c == nc)continue;
        if (graph[nr][nc] == -1) {
            graph[nr][nc] = graph[fishes[i].r][fishes[i].c];
            graph[fishes[i].r][fishes[i].c] = -1;
            fishes[i].r = nr;
            fishes[i].c = nc;
            continue;
        }

        int f2 = graph[nr][nc];
        graph[nr][nc] = graph[fishes[i].r][fishes[i].c];
        graph[fishes[i].r][fishes[i].c] = f2;

        fish tmp = fishes[i];
        fishes[i].r = nr;
        fishes[i].c = nc;
        fishes[f2].r = tmp.r;
        fishes[f2].c = tmp.c;

    }
}

void sharkMove(int sum) {
    ans = max(ans, sum);

    int tGraph[L][L];
    fish tFishes[N];
    memcpy(tGraph, graph, sizeof(graph));
    memcpy(tFishes, fishes, sizeof(fishes));

    fishMove();
    for (int i = 1; i < L; i++) {
        int nr = shk.r + dr[shk.d] * i;
        int nc = shk.c + dc[shk.d] * i;
        if (outOfBound(nr, nc)) break;
        if (!fishes[graph[nr][nc]].alive)continue;
        if (graph[nr][nc] == -1)continue;
        int fn = graph[nr][nc];
        fish os = shk;

        graph[shk.r][shk.c] = -1;
        graph[nr][nc] = -2;
        fishes[fn].alive = false;
        shk = {nr, nc, fishes[fn].d};

        sharkMove(sum + fn + 1);

        graph[nr][nc] = fn;
        fishes[fn].alive = true;
        graph[os.r][os.c] = -2;
        shk = os;
    }
    memcpy(graph, tGraph, sizeof(graph));
    memcpy(fishes, tFishes, sizeof(fishes));
}

void solve() {
    fishes[graph[0][0]].alive = false;
    shk = fishes[graph[0][0]];
    int first = graph[0][0];
    graph[0][0] = -2;

    sharkMove(first + 1);

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}