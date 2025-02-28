#include <bits/stdc++.h>
using namespace std;

#define INF 500'001

vector<pair<int,int>> edges[51]; // 인덱스: src, first: dest, second: dist
int distList[51]; // 0번으로 부터의 거리
priority_queue<pair<int,int>> pq; // 거리, dest
bool chk[51];
int ans;

int solution(int n, vector<vector<int>> road, int k) {
    
    // init
    for(int i=0;i<road.size();i++){
        vector<int> iter = road[i];
        edges[iter[0]-1].emplace_back(iter[1]-1,iter[2]);
        edges[iter[1]-1].emplace_back(iter[0]-1,iter[2]);
    }
    
    for(int i=0;i<n;i++){
        distList[i] = INF;
    }
    pq.push({0,0});
    
    // solve
    while(!pq.empty()){
        pair<int,int> cur = pq.top();
        pq.pop();
        int dist = cur.first;
        int dest = cur.second;

        distList[dest] = dist;
        
        for(pair<int,int> next : edges[dest]){
            if(dist + next.second > distList[next.first]) continue;
            pq.push(make_pair(dist + next.second, next.first));
        }
    }
    
    // for(int i=0;i<n;i++){
    //     cout << distList[i] << ' ';
    // }cout << endl;
    for(int i=0;i<n;i++){
        if(distList[i]<=k)ans++;
    }
    
    return ans;
}