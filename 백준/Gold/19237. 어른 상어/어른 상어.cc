#include <bits/stdc++.h>

#define MAX_SIZE 21
#define MAX_MOVEMENT 1000

using namespace std;

int n, m, k;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool outOfBound(int r, int c) {
    return (r < 0 || r >= n || c < 0 || c >= n);
}

struct smell {
    int sharkN;
    int time;
};

smell graph[MAX_SIZE][MAX_SIZE];
int strongShark[MAX_SIZE][MAX_SIZE];

stack<int> dieShark;

// 1:위,2:아래,3:왼,4:오른 -1
class shark {
public:
    int number;
    int curD;
    int curR;
    int curC;
    int nextD[4][4]{};

    shark() {}

    shark(int number, int curR, int curC) {
        this->number = number;
        this->curR = curR;
        this->curC = curC;
    }

    void move() {
        for (int i = 0; i < 4; i++) {
            int nd = nextD[curD][i];
            int nr = curR + dr[nd];
            int nc = curC + dc[nd];
            if (outOfBound(nr, nc))continue;
            if (graph[nr][nc].sharkN)continue;
            curR = nr;
            curC = nc;
            curD = nd;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nd = nextD[curD][i];
            int nr = curR + dr[nd];
            int nc = curC + dc[nd];
            if (outOfBound(nr, nc))continue;
            if (graph[nr][nc].sharkN != number)continue;
            curR = nr;
            curC = nc;
            curD = nd;
            return;
        }
    }


    void makeSmell() {
        graph[curR][curC] = {number, k};
    }
};

vector<shark> sharks;

void init() {
    cin >> n >> m >> k;
    sharks.resize(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (a != 0) {
                sharks[a - 1] = shark(a, i, j);
            }
            graph[i][j] = {0, 0};
            strongShark[i][j] = 40001;
        }
    }
    for (int i = 0; i < m; i++) {
        int d;
        cin >> d;
        sharks[i].curD = d - 1;
    }
    for (int i = 0; i < m; i++) {
        for (auto &j: sharks[i].nextD) {
            for (int &l: j) {
                int a;
                cin >> a;
                l = a - 1;
            }
        }
    }
}


void decraseTime() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!graph[i][j].sharkN)continue;
            graph[i][j].time--;
            if (!graph[i][j].time)
                graph[i][j].sharkN = 0;

        }
    }
}

void solve() {
    for (int i = 0; i <= MAX_MOVEMENT; i++) {
        if (m == 1) {
            cout << i;
            return;
        }
        for (int j = 0; j < m; j++) {
            sharks[j].makeSmell();
        }
        for (int j = 0; j < m; j++) {
            strongShark[sharks[j].curR][sharks[j].curC] = 40001;
            sharks[j].move();
            if (strongShark[sharks[j].curR][sharks[j].curC] < sharks[j].number) {
                dieShark.push(j);
            } else {
                strongShark[sharks[j].curR][sharks[j].curC] = sharks[j].number;
            }
        }
        while (!dieShark.empty()) {
            sharks.erase(sharks.begin() + dieShark.top());
            dieShark.pop();
            m--;
        }
        decraseTime();
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}