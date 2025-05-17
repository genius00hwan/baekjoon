import java.util.*;
class Solution {
    int target;
    int ans;
    int n;
    public void dfs(int cur, int cnt){
        if(cur==target){
            ans = Math.min(cnt,ans);
        }
        int tmp = n;
        for(int i=1;i<=8-cnt;i++){
            dfs(cur+tmp,cnt+i);
            dfs(cur-tmp,cnt+i);
            dfs(cur/tmp,cnt+i);
            dfs(cur*tmp,cnt+i);
            tmp = n + tmp*10;
        }
    }
    public int solution(int N, int number) {
        n = N;
        target = number;
        ans = 10;
        dfs(0,0);
        if(ans==10){
            return -1;
        }
        return ans;
    }
}