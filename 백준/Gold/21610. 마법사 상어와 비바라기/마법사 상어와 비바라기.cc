#include <bits/stdc++.h>

using namespace std;

int dr[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int dc[8] = {-1, -1, -1, 0, 1, 1, 1, 0};


int n, m;

int ans;

struct cld {
    int r, c;
};

struct bucket {
    int v;//물의 양
    bool rained; //방금 비 왔는지
};

struct cmd {
    int d, s;
};

vector<cld> clds;
bucket graph[51][51];
vector<cmd> cmds;
//
//void print_clouds() {
//    cout << "clouds : " << endl;
//    for (cld c: clds) {
//        cout << c.r << ',' << c.c << "/";
//    }
//    cout << endl << endl;
//}
//
//void print_status() {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << graph[i][j].v << ' ';
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

void init() {
    cin >> n >> m;
    int w;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w;
            graph[i][j] = {w, false};
        }
    }
    int d, s;
    while (m--) {
        cin >> d >> s;
        cmds.push_back({d, s});
    }
    clds.push_back({n - 1, 0});
    clds.push_back({n - 1, 1});
    clds.push_back({n - 2, 0});
    clds.push_back({n - 2, 1});
}

void mvCld(int d, int s) {
    for (auto &c: clds) {
        int nr = (c.r + (dr[d] * s) % n + n) % n;
        int nc = (c.c + (dc[d] * s) % n + n) % n;
        c.r = nr;
        c.c = nc;
    }
}

void rain() {
    for (cld c: clds) {
        graph[c.r][c.c].v += 1;
        graph[c.r][c.c].rained = true;
    }
}

void cpWtr() {
    vector<pair<cld, int>> tmp;
    for (cld c: clds) {
        for (int i = 0; i < 8; i += 2) {
            int nr = c.r + dr[i];
            int nc = c.c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (!graph[nr][nc].v)continue;
            graph[c.r][c.c].v += 1;
        }
    }
    clds.clear();
}

void mkCld() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j].rained) {
                graph[i][j].rained = false;
                continue;
            }
            if (graph[i][j].v < 2) continue;
            graph[i][j].v -= 2;
            clds.push_back({i, j});
        }
    }
}


void solve() {
    for (cmd c: cmds) {
        mvCld(c.d % 8, c.s);

        rain();

        cpWtr();

        mkCld();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += graph[i][j].v;
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