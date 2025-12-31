#include <bits/stdc++.h>

using namespace std;

int graph[101][101]; // 1: 시작, 2: 목표, 0: 통로, -1: 벽

pair<int,int>start;
pair<int,int> goal;
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
int n,m;
int ans;

void init(vector<string>);
bool bfs();
int solve();
bool oob(int,int);
int solution(vector<string> maps) {
    init(maps);
    return solve();
}

void init(vector<string> maps){
    n = maps.size();
    m = maps[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char t = maps[i][j];
            int cur = 0;
            if(t=='S'){
                start = make_pair(i,j);
            }else if(t=='E'){
                goal = make_pair(i,j);
            }else if(t=='L'){
                cur = 2; // 초대 목표
            }else if(t=='X'){
                cur = -1;
            }
            graph[i][j] = cur;
        }
    }
}

int solve(){
    if(!bfs()) return -1;

    graph[goal.first][goal.second] = 2;
    graph[start.first][start.second] = 0;
    
    // cout << endl; // debug
    if(!bfs()) return -1;
    
    return ans;
}

bool bfs(){
    int dist[101][101];
    memset(dist,0,sizeof(dist));
    queue<pair<int,int>> q;
    q.push({start});
    dist[start.first][start.second] = 1;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        // cout << cur.first << ','<< cur.second <<":"<<dist[cur.first][cur.second]<< "->"; //debug
        
        if(graph[cur.first][cur.second] == 2){
            start = cur;
            ans += dist[cur.first][cur.second] -1;
            return true;
        }
        
        for(int i=0;i<4;i++){
            int nr = cur.first+dr[i];
            int nc = cur.second+dc[i];
            if(oob(nr,nc))continue;
            if(graph[nr][nc]<0)continue;
            if(dist[nr][nc])continue;
            q.push({nr,nc});
            dist[nr][nc] = dist[cur.first][cur.second] + 1;
        }
    }
    return false;
}

bool oob(int r, int c){
    return r<0|| r>=n || c<0 || c>=m;
}