#include <bits/stdc++.h>

#define MX 11
using namespace std;
int N;
int tar;
int graph[1000][1000];
int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};
pair<int, int> tarP;
string ans;

void init() {
    cin >> N >> tar;
}

bool oob(int r, int c) {
    return r < 0 || r >= N || c < 0 || c >= N;
}

string solve() {
    pair<int, int> cur = {N / 2, N / 2};
    int cd = 0;
    for (int i = 1; i <= (N*N); i++) {
        graph[cur.first][cur.second] = i;
        if(i==tar) tarP = cur;
        int rd = (cd + 1) % 4;
        int rr = cur.first + dr[rd];
        int rc = cur.second + dc[rd];
        if (oob(rr,rc)||graph[rr][rc]) {// 오른쪽에 값이 있는 경우 -> 직진
            cur = {cur.first+dr[cd], cur.second+dc[cd]};
            continue;
        }
        // 오른쪽에 값이 없는 경우 -> 오른쪽으로 회전
        cd = rd;
        cur = {rr, rc};
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ans += to_string(graph[i][j]) + ' ';
        }ans += '\n';
    }
    ans += to_string(tarP.first+1) + ' ' + to_string(tarP.second+1);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cout << solve();
    return 0;
}
