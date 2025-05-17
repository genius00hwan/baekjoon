class Solution {
    
    public int ans;
    public int N;
    public int[] nums;
    public void dfs(int cnt, int cur){
        if(cnt==nums.length){
            if(cur==N){
                ans++;
            }
            return;
        }
        dfs(cnt+1,cur+nums[cnt]);
        dfs(cnt+1,cur-nums[cnt]);
    }
    public int solution(int[] numbers, int target) {
        ans = 0;
        nums = numbers;
        N = target;
        dfs(0,0);
        return ans;
    }
}