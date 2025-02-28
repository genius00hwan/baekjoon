#include <bits/stdc++.h>

using namespace std;
int target;
int n;
int ans = 9;

void dfs(int cur, int cnt){
    if(cur == target){
        ans = min(ans,cnt);
    }
    int t = n;
    for(int i=0;i<8-cnt;i++){
        dfs(cur+t,cnt+i+1);
        dfs(cur-t,cnt+i+1);
        dfs(cur*t,cnt+i+1);
        dfs(cur/t,cnt+i+1);
        t = n + t*10;
    }
}
int solution(int N, int number) {
    target = number;
    n = N;
    dfs(0,0);
    return ans == 9 ? -1 : ans;
}