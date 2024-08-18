#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int graph[21][21];
bool chk[21][21];

// 동 남 서 북
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

bool oob(int r, int c) {
    return r < 0 || r >= n || c < 0 || c >= m;
}


class dice {
public:
    int front, up, right;
    // 앞면으로 뒷면이, 윗면으로 아랫면이, 오른쪽 면으로 왼쪽 면이 결정된다.
    int r, c;
    // 현재 죄표를 저장하여, 이동하고, 점수를 계산한다.

    int dir;
    // 방향을 저장하여 이동한다.

    int point;
    // 점수를 저장하고 마지막에 출력한다.

    dice(int, int, int, int, int, int);
    // 초기값.

    void goEast();

    void goSouth();

    void goWest();

    void goNorth();

    /**
     * 동서남북 4방중 1로 이동할 수 있다.
     */

    void move();

    /**
     * 정해져 있는 방향에 맞게 이동한다.
     */
    void turn();

    /**
     * 방향을 결정한다.
     */


    int getValue();

    /**
     * 점수를 계산할때는 밑면을 기준으로 한다.
     */

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

/**
 * 동쪽으로 이동 : F <- F, U <- L(7-R), R <- U
 * 남쪽으로 이동 : F <- U, U <-B(7-F), R <- R
 * 서쪽으로 이동 : F <- F, U <- R, R <- D(7-U)
 * 북쪽으로 이동 : F <- D(7-U), U <-F, R <- R
 */
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

// 방향을 보고 동서남북 중 1로 이동
void dice::move() {
    if (oob(r + dr[dir], c + dc[dir]))
        dir = (dir + 2) % 4;
    // 범위를 벗어나면 반대 방향


    if (dir == 0) goEast();
    else if (dir == 1)goSouth();
    else if (dir == 2)goWest();
    else goNorth();

    r = r + dr[dir];
    c = c + dc[dir];
}

/**
 *   그래프에 있는 값 (A)과 주사위 아랫면 (B) 을 비교하고 회전
 *  A < B : 반시계 방향 (dir+=1)
 *  A > B : 시계 방향 (dir-=1)
 *  
 *  동 남 서 북
 *  dr[] = {0, 1, 0, -1}
*   dc[] = {1, 0, -1, 0}
 */
void dice::turn() {
    if (graph[r][c] < getValue())
        dir = (dir + 1) % 4;
    else if (graph[r][c] > getValue()) {
        dir = (dir + 3) % 4;
    }
}


int dice::getValue() {
    // 밑면을 반환
    return 7 - up;
}

/**
 * bfs를 돌리면서 같은값을 찾아서 갯수를 구한다.
 */

void dice::addPoint() {
    memset(chk, false, sizeof chk);
    // visited 배열을 전역변수로 선언해둠
    queue<pair<int, int>> q;
    q.push({r, c});
    point += graph[r][c];
    chk[r][c] = true;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if (oob(nr, nc))continue;
            if (chk[nr][nc])continue;
            if (graph[nr][nc] != graph[r][c])continue;
            point += graph[nr][nc];
            q.push({nr, nc});
            chk[nr][nc] = true;
        }
    }

}
