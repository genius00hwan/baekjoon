#include <bits/stdc++.h>

using namespace std;

pair<int,int> price[7]; // 할인된가격, 할인율
vector<vector<int>> users;
vector<int> emoticons;
pair<int,int>ans;

void dfs(int idx){
    if(idx == emoticons.size()){
        pair<int,int> cur = {0,0};
        for(int i=0;i<users.size();i++){
            int tmp=0;
            for(int j=0;j<emoticons.size();j++){
                if(users[i][0]>price[j].second)continue;
                tmp+=price[j].first;
            }
            if(tmp>=users[i][1]){
                cur.first++;
                continue;
            }
            cur.second+=tmp;
        }
        
        if(ans.first<cur.first || (ans.first == cur.first && ans.second < cur.second)){
            ans = cur;
        }
        return;
    }
    for(int rate=10;rate<=40;rate+=10){
        price[idx].first = (100 - rate) * emoticons[idx] / 100;
        price[idx].second = rate;
        dfs(idx+1);
    }
    
}

vector<int> solution(vector<vector<int>> inputUsers, vector<int> inputEmoticons) {
    vector<int> ret;
    users = inputUsers;
    emoticons = inputEmoticons;
    dfs(0);
    ret.push_back(ans.first);
    ret.push_back(ans.second);
    return ret;
}