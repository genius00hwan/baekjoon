#include <bits/stdc++.h>

using namespace std;
int ans;
int numOfAddedServer[24];
int m;
int k;
void addServer(int cur, int numOfPlayer){
    int numOfRequireServer = numOfPlayer/m;
    if(numOfAddedServer[cur]>=numOfRequireServer){
        return;
    }
    int numOfServerToAdd = numOfRequireServer - numOfAddedServer[cur];
    ans+= numOfServerToAdd;
    for(int h = cur;h<min(cur+k,24);h++){
        numOfAddedServer[h]+=numOfServerToAdd;
    }
}

int solution(vector<int> players, int inputM, int inputK) {
    m = inputM;
    k = inputK;
    for(int i=0;i<24;i++){
        addServer(i,players[i]);
    }
    return ans;
}