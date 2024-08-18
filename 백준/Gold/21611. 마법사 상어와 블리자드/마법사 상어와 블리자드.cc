#include <bits/stdc++.h>

using namespace std;

int n, m;
int dr[] = {0, 1, 0, -1};
int dc[] = {-1, 0, 1, 0};
int rd[] = {2, 3, 1, 0};

int ans;

struct cmd {
    int d, s;
};

vector<int> beads;
vector<cmd> cmds;
int graph[51][51];
bool chk[51][51];

bool oob(int r, int c) {
    return r < 0 || r >= n || c < 0 || c >= n;
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (int b: beads) {
        cout << b << " ";
    }
    cout << endl;
}

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    pair<int, int> cur = {n / 2, n / 2};
    int cd = 0;
    graph[cur.first][cur.second] = -1;
    chk[cur.first][cur.second] = true;
    for (int i = 1; i < n * n; i++) {
        int nr = cur.first + dr[cd];
        int nc = cur.second + dc[cd];
        if(oob(nr,nc))continue;

        if (graph[nr][nc])
            beads.push_back(graph[nr][nc]);
        chk[nr][nc] = true;
        cur = {nr, nc};
        cd = (cd + 1) % 4;
        if (chk[cur.first + dr[cd]][cur.second + dc[cd]])
            cd = (cd + 3) % 4;
    }

    while (m--) {
        cmd c;
        cin >> c.d >> c.s;
        cmds.push_back(c);
    }
}

void atk(int d, int s) {
    d = rd[d % 4];
    for (int i = 1; i <= s; i++) {
        graph[n / 2 + (dr[d] * i)][n / 2 + (dc[d] * i)] = 0;
    }
}


void pull() {
    memset(chk, false, sizeof(chk));
    beads.clear();
    pair<int, int> cur = {n / 2, n / 2};
    int cd = 0;
    graph[cur.first][cur.second] = -1;
    chk[cur.first][cur.second] = true;
    int aCnt = 0;
    for (int i = 1; i < n * n; i++) {
        int nr = cur.first + dr[cd];
        int nc = cur.second + dc[cd];
        if(oob(nr,nc))continue;

        if (graph[nr][nc])
            beads.push_back(graph[nr][nc]);
        else aCnt++;
        chk[nr][nc] = true;
        cur = {nr, nc};
        cd = (cd + 1) % 4;
        if (chk[cur.first + dr[cd]][cur.second + dc[cd]])
            cd = (cd + 3) % 4;
    }
    memset(chk, false, sizeof(chk));
    cur = {n / 2, n / 2};
    cd = 0;
    graph[cur.first][cur.second] = -1;
    chk[cur.first][cur.second] = true;

    for (int a: beads) {
        int nr = cur.first + dr[cd];
        int nc = cur.second + dc[cd];
        if(oob(nr,nc))continue;

        graph[nr][nc] = a;
        chk[nr][nc] = true;
        cur = {nr, nc};
        cd = (cd + 1) % 4;
        if (chk[cur.first + dr[cd]][cur.second + dc[cd]])
            cd = (cd + 3) % 4;
    }
    while (aCnt--) {
        int nr = cur.first + dr[cd];
        int nc = cur.second + dc[cd];
        if(oob(nr,nc))continue;

        graph[nr][nc] = 0;
        chk[nr][nc] = true;
        cur = {nr, nc};
        cd = (cd + 1) % 4;
        if (chk[cur.first + dr[cd]][cur.second + dc[cd]])
            cd = (cd + 3) % 4;
    }
}


int bomb() {
    memset(chk, false, sizeof(chk));
    int mxCnt = 0;
    stack<pair<int, int>> bombed;
    pair<int, int> cur = {n / 2, n / 2};
    int cd = 0;
    graph[cur.first][cur.second] = -1;
    chk[cur.first][cur.second] = true;
    int ptr = graph[cur.first][cur.second];
    bombed.push({cur.first, cur.second});
    for (int i = 1; i < n * n; i++) {
        int nr = cur.first + dr[cd];
        int nc = cur.second + dc[cd];
        if(oob(nr,nc))continue;

        if (!ptr)break;
        if (ptr != graph[nr][nc]) {
            mxCnt = max((int) bombed.size(), mxCnt);
            if ((int) bombed.size() >= 4) {
                while (!bombed.empty()) {
                    ans += graph[bombed.top().first][bombed.top().second];
                    graph[bombed.top().first][bombed.top().second] = 0;
                    bombed.pop();
                }
            }
            while (!bombed.empty())bombed.pop();
        }
        bombed.push({nr, nc});
        ptr = graph[nr][nc];
        chk[nr][nc] = true;
        cur = {nr, nc};
        cd = (cd + 1) % 4;
        if (chk[cur.first + dr[cd]][cur.second + dc[cd]])
            cd = (cd + 3) % 4;
    }
    return mxCnt;
}

void trans() {
    memset(chk, false, sizeof(chk));
    beads.clear();
    stack<pair<int, int>> transed;
    pair<int, int> cur = {n / 2, n / 2};
    int cd = 0;
    graph[cur.first][cur.second] = -1;
    chk[cur.first][cur.second] = true;
    int ptr = graph[cur.first][cur.second];
    for (int i = 1; i < n * n; i++) {
        int nr = cur.first + dr[cd];
        int nc = cur.second + dc[cd];
        if(oob(nr,nc))continue;

        if (!ptr)break;
        if (ptr != graph[nr][nc]) {
            beads.push_back(transed.size());
            beads.push_back(ptr);
            while (!transed.empty())transed.pop();
        }
        transed.push({nr, nc});
        ptr = graph[nr][nc];
        chk[nr][nc] = true;
        cur = {nr, nc};
        cd = (cd + 1) % 4;
        if (chk[cur.first + dr[cd]][cur.second + dc[cd]])
            cd = (cd + 3) % 4;
    }

    memset(chk, false, sizeof(chk));
    cur = {n / 2, n / 2};
    cd = 0;
    graph[cur.first][cur.second] = -1;
    chk[cur.first][cur.second] = true;

    for (int a: beads) {
        if (a <= 0)continue;
        int nr = cur.first + dr[cd];
        int nc = cur.second + dc[cd];
        if(oob(nr,nc))continue;
        graph[nr][nc] = a;
        chk[nr][nc] = true;
        cur = {nr, nc};
        cd = (cd + 1) % 4;
        if (chk[cur.first + dr[cd]][cur.second + dc[cd]])
            cd = (cd + 3) % 4;
    }

}

void solve() {
    for (cmd c: cmds) {
        atk(c.d, c.s);
        pull();

        while (bomb() >= 4) {
            pull();
        }
        trans();
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