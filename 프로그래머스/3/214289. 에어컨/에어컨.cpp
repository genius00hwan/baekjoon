#include <bits/stdc++.h>

#define MAX 55

using namespace std;
int mem[1002][52];
int temp, t1, t2, a, b;
int s,e,d;
bool exist[1002];
int ans;
int total;
void init(int, int ,int, int, int , vector<int>);
void solve();
int solution(int inTemp, int inT1, int inT2, int inA, int inB, vector<int> inOnboard) {
    init(inTemp, inT1, inT2, inA, inB, inOnboard);
    solve();
    return ans;
}

void init(int inTemp, int inT1, int inT2, int inA, int inB, vector<int> inOnboard){
    temp = inTemp+10;
    t1 = inT1+10;
    t2 = inT2+10;
    a = inA;
    b = inB;
    ans = INT_MAX;
    total = inOnboard.size();
    for(int i=0;i<total;i++){
        exist[i] = inOnboard[i]==1;
    }
    memset(mem,MAX,sizeof mem);
    s = t1;
    e = t2;
    if(temp<t1){
        d = -1;
        s = temp;
    }
    if(temp>t2){
        d = 1;
        e = temp;
    }
    mem[0][temp] = 0;
    mem[0][temp-d] = a;
}

void solve(){
    for(int m=1;m<total;m++){
        int l,r;
        if(exist[m]){l = t1;r = t2;}
        else{l=s;r=e;}
        for(int t=l;t<=r;t++){
            if(t==temp){
                mem[m][t] = min(mem[m-1][t],mem[m-1][t-d]);
                continue;
            }
            mem[m][t] = min(
                min(
                    mem[m-1][t-d],
                    mem[m-1][t]+b
                ), mem[m-1][t+d]+a
            );
            
        }
    }
    
    for(int t=s;t<=e;t++){            
        ans = min(mem[total-1][t], ans);
    }
    
}