import java.util.*;
class Solution {
    int[][] mem;
    int MAX = 130;
    public int solution(int[][] info, int n, int m) {
        int ans = MAX;
        mem = new int[121][121];
        for(int i=0;i<120;i++){
            for(int j=0;j<120;j++){
                mem[i][j] = MAX;
            }
        }
        mem[0][0] = info[0][0];
        mem[0][info[0][1]] = 0;
        for(int i=1;i<info.length;i++){
            for(int j=0;j<=m;j++){
                mem[i][j] = mem[i-1][j]+info[i][0];
                if(j>=info[i][1]){
                    mem[i][j] = Math.min(mem[i][j],mem[i-1][j-info[i][1]]);
                }
                
            }
            
        }
        // for(int i=0;i<info.length;i++){
        //     for(int j=0;j<=m;j++){
        //         if(mem[i][j]>=MAX)System.out.print("?");
        //         else
        //             System.out.print(mem[i][j]);        
        //     }System.out.println();
        // }
        for(int j=0;j<m;j++){
            ans = Math.min(ans,mem[info.length-1][j]);
        }
        ans = ans >= n?-1:ans;
        return ans;
    }
}