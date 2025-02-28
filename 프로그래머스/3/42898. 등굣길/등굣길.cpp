#include <bits/stdc++.h>

using namespace std;

#define MOD 1'000'000'007

long long graph[102][102];
long long ans;
int solution(int m, int n, vector<vector<int>> puddles) {
    // init
    for(int i=0;i<puddles.size();i++){
        graph[puddles[i][1]-1][puddles[i][0]-1] = -1;
    }
    for(int i=1;i<m;i++){
        if(graph[0][i]==-1) break;
        graph[0][i] = 1; 
    }
    for(int i=1;i<n;i++){
        if(graph[i][0]==-1) break;
        graph[i][0]=1; 
    }
    
    // solve
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(graph[i][j]==-1) continue;
            long long l = (graph[i][j-1]==-1) ? 0 : graph[i][j-1];
            long long u = (graph[i-1][j]==-1) ? 0 : graph[i-1][j];
          
            graph[i][j] = (l + u) % MOD;
        }
    }
    
    return graph[n-1][m-1];
}