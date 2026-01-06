#include <bits/stdc++.h>

using namespace std;

int ans;
int n;
vector<vector<int>> q;
vector<int> cnt;

int compare(vector<int> cur, vector<int> input){
    vector<int> diff;
    set_difference(
        cur.begin(), cur.end(),
        input.begin(), input.end(),
        back_inserter(diff));
    return diff.size();
}
void dfs(int v, vector<int> cur){
    if(cur.size()==5){
        for(int i=0;i<q.size();i++){
            int t = 5 - compare(cur, q[i]);
            if(t!=cnt[i]) return;
        }
        // for(int i=0;i<5;i++){
        //     cout << cur[i] <<' ';
        // }cout << endl;
        ans++;
        return;
    }
    if(v>n) return;
    dfs(v+1,cur);
    cur.push_back(v);
    dfs(v+1,cur);
}
void init(int inputN, vector<vector<int>> inputQ, vector<int> inputCnt){
    n = inputN;
    q = inputQ;
    cnt = inputCnt;
}

int solution(int inputN, vector<vector<int>> inputQ, vector<int> inputCnt){
    init(inputN,inputQ,inputCnt);
    vector<int> c;
    dfs(1,c);
    return ans;
}