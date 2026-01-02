#include <bits/stdc++.h>

#define MAX 1000002
using namespace std;


int mem[MAX];
int x,y,n;
int ans;

int solve();
void init(int, int, int);
int dp(int);
int solution(int inputX, int inputY, int inputN) {
    init(inputX,inputY,inputN);
    return solve();
}
void init(int inputX, int inputY, int inputN){
    x = inputX;
    y = inputY;
    n = inputN;
    
    memset(mem,MAX,sizeof mem);
    mem[x]=0;
}

int solve(){
    for(int cur=x;cur<=y;cur++){
        if(mem[cur]==MAX)continue;
        if(cur*2<=y){
            mem[cur*2] = min(mem[cur*2],mem[cur]+1);
        }
        if(cur*3<=y){
            mem[cur*3] = min(mem[cur*3],mem[cur]+1);
        }   
        if(cur+n<=y){
            mem[cur+n] = min(mem[cur+n],mem[cur]+1);
        }
    }
    if(mem[y]>=MAX) return -1;
    return mem[y];
    
}


