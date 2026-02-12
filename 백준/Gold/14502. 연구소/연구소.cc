#include <bits/stdc++.h>

using namespace std;


struct node {
    int c;
    int r;
};

int n, m, ans;
int lab[9][9];
bool vst[9][9];
vector<node> cand;
node newW[3];
int cd[4] = {0, 1, 0, -1};
int rd[4] = {1, 0, -1, 0};


void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) {
                cand.push_back({i, j});
            }
        }
    }
}

void bfs(node s) {
    queue<node> q;
    q.push(s);
    vst[s.c][s.r] = true;
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nc = cur.c + cd[i];
            int nr = cur.r + rd[i];

            if (nc < 0 || nc >= n || nr < 0 || nr >= m) continue;
            if (vst[nc][nr]) continue;
            if (lab[nc][nr] != 0)continue;

            q.push({nc, nr});
            vst[nc][nr] = true;
            lab[nc][nr] = 4;
        }
    }

}


void clear() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vst[i][j] = false;
            if (lab[i][j] == 3 || lab[i][j] == 4)
                lab[i][j] = 0;
        }
    }
}

void solve(int idx, int cnt) {
    if (idx >= cand.size() && cnt < 3) return;
    if (cnt == 3) {
        for (node a: newW) {
            lab[a.c][a.r] = 3;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lab[i][j] == 2)
                    bfs({i, j});
            }
        }
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lab[i][j] == 0)
                    tmp++;
            }
        }
        ans = max(ans, tmp);
        clear();
        return;
    }
    newW[cnt] = cand[idx];
    solve(idx + 1, cnt + 1);
    solve(idx + 1, cnt);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve(0,0);
    cout << ans << '\n';
}
