class Solution {
    public int[] mem;
    public int N;
    public int MOD = 10007;

    public int solution(int n, int[] tops) {
        N = 2*n+1;
        mem = new int[N+1];
        mem[0]=1;
        mem[1]=1;
        for(int i=2;i<=N;i++){
            if(i%2==0&&tops[i/2-1]==1){
                mem[i]=(mem[i-1]*2+mem[i-2])%MOD;
                continue;
            }
            mem[i]=(mem[i-1]+mem[i-2])% MOD;
            
        }
        return mem[N];
    }
}