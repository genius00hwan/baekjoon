#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MAX 51

int ans;
struct edge{
    int dest;
    int dist;
};
struct cmp{
    bool operator()(edge e1,edge e2){
        return e1.dist < e2.dist;
    }
};
vector<edge> edges[MAX]; // 목적지, 거리
priority_queue<edge,vector<edge>,cmp>pq;
int v[MAX];

int solution(int n, vector<vector<int>> road, int k) {
    // init
    for(auto e : road){
        edges[e[0]-1].push_back({e[1]-1,e[2]});
        edges[e[1]-1].push_back({e[0]-1,e[2]});
    }
    for(int i=1;i<n;i++){
        v[i] = INF;
    }
    v[0]=0;
    pq.push({0,0});
    
    // sol
    while(!pq.empty()){
        edge cur = pq.top();
        pq.pop();
        for(edge  e : edges[cur.dest]){
            if(v[e.dest] <= cur.dist + e.dist) continue;
            v[e.dest] = cur.dist + e.dist;
            pq.push({e.dest,cur.dist + e.dist});
        }
    }
    
    for(int i=0;i<n;i++){
        ans += (v[i]<=k);
    }
    return ans;
}