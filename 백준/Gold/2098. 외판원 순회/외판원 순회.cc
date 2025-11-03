#include<bits/stdc++.h>

using namespace std;

#define MAX 16
#define INF 99999999

int graph[MAX][MAX];
int mem[MAX][1<<MAX];
int N;

void solve();
void init();
int dfs(int,int);
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    init();
    solve();
    return 0;
}

void init(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> graph[i][j];
        }
    }
    memset(mem,-1,sizeof mem);
}
void solve(){
    cout << dfs(0,1) <<'\n';
}
int dfs(int cur, int chk){
    if (chk == (1<<N)-1){
        if(graph[cur][0] == 0)
            return INF;
        return graph[cur][0];
    }

    if (mem[cur][chk] != -1)
        return mem[cur][chk];

    mem[cur][chk] = INF;

    for (int i=0; i<N; i++){
        if (graph[cur][i]==0)
            continue;
        if ((chk & (1<<i)) == (1<<i))
            continue;
        mem[cur][chk] = min(mem[cur][chk], graph[cur][i] + dfs(i, chk | 1<<i));
    }

    return mem[cur][chk];
}
