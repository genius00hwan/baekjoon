#include <bits/stdc++.h>

#define L 4
using namespace std;

int fdr[] = {1, 0, -1, -1, -1, 0, 1, 1};
int fdc[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int sdr[] = {-1, 0, 1, 0};
int sdc[] = {0, -1, 0, 1};

struct loc {
    int smell; // 0~2;
    bool isSrk;
    queue<int> fishes;//물고기 방향들
};

struct node {
    int r, c;
};

int tmpR[3];
int sR[3]; // 상어의 이동 경로
int mxF;

queue<pair<node, int>> tmpFish;//복제되기 전 물고기들 저장

int m, s;
loc graph[L][L];
bool chk[L][L];

node srkLoc;

bool oob(int r, int c) {
    return r < 0 || r >= L || c < 0 || c >= L;
}

void print_fish() {
    cout << "fishes' direction : \n";
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            cout << " " << i << ',' << j << ": ";
            int fn = graph[i][j].fishes.size();
            while (fn--) {
                int tmp = graph[i][j].fishes.front();
                graph[i][j].fishes.pop();
                cout << tmp << ' ';
                graph[i][j].fishes.push(tmp);
            }
            cout << "<" << graph[i][j].smell << "> |";
        }
        cout << '\n';
    }
    cout << "\n------------\n";


}

void print_shk() {
    cout << "\nshark's status :\n";
    cout << srkLoc.r << ',' << srkLoc.c << "\n";
    cout << "footprint : ";
    for (int i = 0; i < 3; i++) {
        cout << sR[i] << ' ';
    }
    cout << "\n------------\n";
}

void init() {
    cin >> m >> s;
    int fr, fc, fd;

    while (m--) {
        cin >> fr >> fc >> fd;
        graph[fr - 1][fc - 1].fishes.push(fd % 8);
    }
    int sr, sc;
    cin >> sr >> sc;
    graph[sr - 1][sc - 1].isSrk = true;
    srkLoc = {sr - 1, sc - 1};
}

void rdCp() {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            int fn = graph[i][j].fishes.size();
            while (fn--) {
                int tmp = graph[i][j].fishes.front();
                graph[i][j].fishes.pop();
                tmpFish.push({{i, j}, tmp});
                graph[i][j].fishes.push(tmp);
            }
        }
    }
}

void mvF() {
    queue<int> tmpG[L][L];
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            int fn = graph[i][j].fishes.size();
            while (fn--) {
                int tmp = graph[i][j].fishes.front();
                graph[i][j].fishes.pop();
                node cur = {i, j};
                for (int d = 0; d < 8; d++) {
                    int nd = (tmp + -d + 8) % 8;
                    int nr = i + fdr[nd];
                    int nc = j + fdc[nd];
                    if (oob(nr, nc))continue;
                    if (graph[nr][nc].isSrk)continue;
                    if (graph[nr][nc].smell) continue;

                    cur = {nr, nc};
                    tmpG[nr][nc].push(nd);
                    break;
                }
                if (cur.r == i && cur.c == j) {
                    tmpG[i][j].push(tmp);
                }
            }
        }
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            while (!tmpG[i][j].empty()) {
                graph[i][j].fishes.push(tmpG[i][j].front());
                tmpG[i][j].pop();
            }
        }
    }

}

int dcdSA() {
    bool chk[L][L] = {false,};
    int cr = srkLoc.r;
    int cc = srkLoc.c;
    int res = 0;
    for (int i = 0; i < 3; i++) {
        int Dir = tmpR[i];
        int nr = cr + sdr[Dir];
        int nc = cc + sdc[Dir];
        if (oob(nr, nc))return -1;
        if (!chk[nr][nc]) {
            chk[nr][nc] = true;
            res += graph[nr][nc].fishes.size();
            cr = nr;
            cc = nc;
        }
    }
    return res;
}

void dfs(int dist) {
    if (dist == 3) {
        int Ate = dcdSA();
        if (mxF < Ate) {
            mxF = Ate;
            for (int i = 0; i < 3; i++) {
                sR[i] = tmpR[i];
            }
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        tmpR[dist] = i;
        dfs(dist + 1);
        tmpR[dist] = 0;
    }
}

void mvS() {
    mxF = -1;
    dfs(0);
    graph[srkLoc.r][srkLoc.c].isSrk = false;
    int cr = srkLoc.r;
    int cc = srkLoc.c;
    for (int i = 0; i < 3; i++) {
        int cd = sR[i];
        int nr = cr + sdr[cd];
        int nc = cc + sdc[cd];

        while (!graph[nr][nc].fishes.empty()) {
            graph[nr][nc].fishes.pop();
            graph[nr][nc].smell = 3;
        }

        cr = nr;
        cc = nc;
        srkLoc = {cr, cc};
    }
    graph[srkLoc.r][srkLoc.c].isSrk = true;
}

void dcSml() {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            if (!graph[i][j].smell)continue;
            graph[i][j].smell--;
        }
    }
}

void doCp() {
    while (!tmpFish.empty()) {
        auto cur = tmpFish.front();
        tmpFish.pop();
        graph[cur.first.r][cur.first.c].fishes.push(cur.second);
    }
}

void play() {
    rdCp();
    mvF();
    mvS();
    dcSml();
    doCp();
}

int calAns() {
    int ans = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            ans += graph[i][j].fishes.size();
        }
    }
    return ans;
}

void solve() {
    while (s--) {
        play();
    }
    cout << calAns();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}