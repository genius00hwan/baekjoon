#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> d, vector<int> p) {
    long long ans = 0;
    long long a = 0;
    long long b = 0;
    for(int i=n-1; i>=0; i--) {
        a -= d[i];
        b -= p[i];
        int cnt = 0;
        while(a < 0 || b < 0) {
            a += cap;
            b += cap;
            cnt++;
        }
        ans += (i + 1) * 2 * cnt;
    }
    return ans;
}