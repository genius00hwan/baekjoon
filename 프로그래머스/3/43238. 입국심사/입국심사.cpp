#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long ans = 1'000'000'001;
    long long s = 1;
    long long e = 0;
    for(int t : times){
        e = max((long long)t,e);
    }
    e = e * n + 1;
    while(e>s){
        long long mid = (s+e)/2;
        
        long long flag = 0;
        for(int t : times){
            flag += mid/t;
        }
        if(flag>=n){
            e = mid;
        }else{
            s = mid+1;
        }
    }
    
    return s;
}