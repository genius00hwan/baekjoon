#include <bits/stdc++.h>


using namespace std;
struct cmp{
    bool operator()(pair<int,int> t1, pair<int,int> t2){
        if(t1.first==t2.first){
            return t1.second > t2.second;
        }
        return t1.first > t2.first;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
void init(vector<vector<int>>);
int solve();
int solution(vector<vector<int>> targets) {
    init(targets);
    return solve();
}
void init(vector<vector<int>> targets){
    for(int i=0;i<targets.size();i++){
        pq.push({targets[i][0],targets[i][1]});
    }
}
int solve(){
    int cnt=1;
    int s = pq.top().first;
    int e = pq.top().second;
    while(!pq.empty()){
        int cs = pq.top().first;
        int ce = pq.top().second;
        pq.pop();
        // cout << "cur: ("<<cs <<','<<ce<<")\n";
        // cout << "\t criteria: ("<<s <<','<<e<<")\n";
        if(cs>=e){
            cnt++;
            s = cs;
            e = ce;
            continue;
        }
        s = max(cs,s);
        e = min(ce,e);
    }
    return cnt;
}
