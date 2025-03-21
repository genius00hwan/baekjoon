#include <bits/stdc++.h>

using namespace std;

map<string,int> dict;
vector<int> solution(string msg) {
    vector<int> ans;
    int cnt=26;
    for(int i=0;i<26;i++){
        char c = 'A'+i;
        string tmp = "";
        tmp += c;
        dict[tmp] = i+1;
    }
    
    int  n = msg.size();
    int idx = 0;
    string cur=msg;
    
    int i = 0;
    int m = msg.size();

    while(i<msg.size()){
        while(dict.find(cur) == dict.end()){
            m--;
            cur = msg.substr(i,m);
        }
        ans.push_back(dict[cur]);
        cur+=msg[i+m];
        dict[cur]=++cnt;
        int o = i;
        i = i+m;
        m = msg.size()-i;
        cur = msg.substr(i,m);
    }
   

    return ans;
}