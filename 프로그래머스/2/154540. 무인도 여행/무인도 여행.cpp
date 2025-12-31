#include <bits/stdc++.h>

using namespace std;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int graph[101][101];
int n,m;
void init(vector<string>);
void solve();
void bfs(int, int);
bool oob(int, int);
vector<int> ans;
bool chk[101][101];
vector<int> solution(vector<string> maps) {
    init(maps);
    solve();
    return ans;
}

void init(vector<string> maps){
    n = maps.size();
    m = maps[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]=='X'){
                graph[i][j] = 0;
                continue;
            }
            graph[i][j] = maps[i][j] - '0';
        }
    }
}
void solve(){
    // int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(chk[i][j])continue;
            if(!graph[i][j])continue;
            // cout << "start: " << i << ", " << j << endl;
            // cnt++;
            bfs(i,j);
        }
    }
    if(ans.empty()){
        ans.push_back(-1);
    }
    sort(ans.begin(), ans.end());
}

void bfs(int sr, int sc){
    queue<pair<int,int>> q;
    q.push({sr,sc});
    chk[sr][sc] = true;
    int cnt = 0;
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        // cout << cr << ", " << cc << ": " << cnt << "<- + " << graph[cr][cc] << endl;
        cnt+=graph[cr][cc];
        for(int i=0;i<4;i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(oob(nr,nc))continue;
            if(chk[nr][nc])continue;
            if(!graph[nr][nc])continue;
            q.push({nr,nc});
            chk[nr][nc] = true;
        }
    }
    ans.push_back(cnt);
}

bool oob(int r, int c){
    return r<0 || r>=n || c<0 || c>=m;
}
