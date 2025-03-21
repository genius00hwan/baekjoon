#include <bits/stdc++.h>

using namespace std;

int mem[500][500]; 
// mem[i][0] = mem[i-1][0]+tri[i][0]
// mem[i][i] = mem[i-1][i-1] + tri[i][i]
// mem[i][j] = max(mem[i-1][j-1],mem[i-1][j]) + tri[i][j]

int solution(vector<vector<int>> tri) {
    int ans = 0;
    int n = tri.size();
    mem[0][0] = tri[0][0];
    for(int i=1;i<n;i++){
        mem[i][0] = mem[i-1][0]+tri[i][0];
        mem[i][i] = mem[i-1][i-1] + tri[i][i];
        ans = max(ans,mem[i][0]);
        ans = max(ans,mem[i][i]);
    }
    for(int i=2;i<n;i++){
        for(int j=1;j<tri[i].size();j++){
            mem[i][j] = max(mem[i-1][j-1],mem[i-1][j]) + tri[i][j];
            ans = max(ans,mem[i][j]);
        }
    }
    return ans;
}