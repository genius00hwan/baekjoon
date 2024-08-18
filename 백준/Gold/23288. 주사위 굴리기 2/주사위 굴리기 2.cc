#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int graph[21][21];
bool chk[21][21];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

bool oob(int r, int c) {
    return r < 0 || r >= n || c < 0 || c >= m;
}


class dice {
public:
    int front, up, right;
    int r, c;
    int dir;
    int point;

    dice(int, int, int, int, int, int);

    void goEast();

    void goSouth();

    void goWest();

    void goNorth();

    void move();

    void turn();

    int getValue();

    void addPoint();
};

dice *D;

void init() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    D = new dice(5, 1, 3, 0, 0, 0);
}

void play() {
    D->move();

    D->addPoint();

    D->turn();
}

void solve() {
    while (k--) {
        play();
    }
    cout << D->point;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}

dice::dice(int front, int up, int right, int r, int c, int dir) {
    this->front = front;
    this->up = up;
    this->right = right;
    this->r = r;
    this->c = c;
    this->dir = dir;
}

void dice::goEast() {
    int oU = up;
    int oR = right;
    up = 7 - oR;
    right = oU;
}

void dice::goSouth() {
    int oU = up;
    int oF = front;
    front = oU;
    up = 7 - oF;
}

void dice::goWest() {
    int oU = up;
    int oR = right;
    up = oR;
    right = 7 - oU;
}

void dice::goNorth() {
    int oU = up;
    int oF = front;
    front = 7 - oU;
    up = oF;
}

void dice::move() {
    if (oob(r + dr[dir], c + dc[dir]))
        dir = (dir + 2) % 4;

    if (dir == 0) goEast();
    else if (dir == 1)goSouth();
    else if (dir == 2)goWest();
    else goNorth();

    r = r + dr[dir];
    c = c + dc[dir];
}

void dice::turn() {
    if (graph[r][c] < getValue())
        dir = (dir + 1) % 4;
    else if (graph[r][c] > getValue()) {
        dir = (dir + 3) % 4;
    }
}


int dice::getValue() {
    return 7 - up;
}

void dice::addPoint() {
    memset(chk, false, sizeof chk);
    int std = graph[r][c];
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    chk[r][c] = true;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if (oob(nr, nc))continue;
            if (chk[nr][nc])continue;
            if (graph[nr][nc] != std)continue;
            cnt++;
            q.push({nr, nc});
            chk[nr][nc]= true;
        }
    }
    point += (cnt * std);

}
