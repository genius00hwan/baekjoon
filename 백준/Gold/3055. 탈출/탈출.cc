#include <bits/stdc++.h>

#define MX 51
using namespace std;

int R, C;
int graph[MX][MX]; // 0: 갈수 있음, 1: 물, 2: 돌
int dist[MX][MX] = {-1,}; // dist는 1부터
bool hour[MX * MX];
pair<int, int> beg;
pair<int, int> dest;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void init() {
    cin >> R >> C;
    string in;
    for (int i = 0; i < R; i++) {
        cin >> in;
        for (int j = 0; j < C; j++) {
            char t = in[j];
            if (t == '*')graph[i][j] = 1;
            else if (t == 'X')graph[i][j] = 2;
            else if (t == 'S') beg = {i, j};
            else if (t == 'D') dest = {i, j};
        }
    }
    fill(*dist, &dist[R][C], -1);
}

bool oob(int r, int c) {
    return r < 0 || r >= R || c < 0 || c >= C;
}

void debug() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << setw(2)<<graph[i][j] ;
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << setw(2) <<dist[i][j] ;
        }
        cout <<endl;
    }
    cout << "-----"<<endl;
}

void rain() {
    vector<pair<int,int>>water;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (graph[i][j] != 1) continue;
            water.emplace_back(i,j);
        }
    }
    for(auto w : water){
        for (int d = 0; d < 4; d++) {
            int nr = w.first + dr[d];
            int nc = w.second + dc[d];
            if (oob(nr, nc))continue;
            if (graph[nr][nc])continue;
            if (dest == make_pair(nr, nc)) continue;
            graph[nr][nc] = 1;
        }
    }
//    debug();
}

int solve() {
    queue<pair<int, int>> q;
    q.push(beg);
    dist[beg.first][beg.second] = 0;
    hour[0] = true;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            int nd = dist[cr][cc] + 1;
            if (oob(nr, nc)) continue;
            if(dist[nr][nc]!=-1)continue;
            if (!hour[nd]) {
                rain();
                hour[nd] = true;
            }
            if (graph[nr][nc]) continue;
            dist[nr][nc] = dist[cr][cc] + 1;
            if (dest == make_pair(nr, nc)) return nd;
            q.push({nr, nc});
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int ans = solve();
    if (ans == -1) cout << "KAKTUS";
    else cout << ans;
}
