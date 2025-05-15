import java.util.*;
import java.io.*;
class Solution {
    public List<Integer>[] graph;
    public int[] degree;
    public int MAX = 1000002;
    public boolean[] chk;
    
    public int checkGraph(int st){
        Queue<Integer>q = new ArrayDeque<>();
        q.offer(st);
        chk[st] = true;
        int vc = 0;
        int ec = 0;
        while(!q.isEmpty()){
            int cur = q.poll();
            vc++;
            for(int nxt : graph[cur]){
                ec++;
                if(!chk[nxt]){
                    chk[nxt] = true;
                    q.offer(nxt);
                }
            }
        }
        if(vc==ec)return 1;
        if(vc+1==ec) return 3;
        return 2;
    }
    public int init(int[][] edges){
        graph = new List[MAX];
        degree = new int[MAX];
        chk = new boolean[MAX];
        int start = 0;
        int mx = 0;
        for(int i=0;i<MAX;i++){
            graph[i] = new ArrayList();
        }
        for(int [] e : edges){
            graph[e[0]].add(e[1]);
            degree[e[1]]++;
            degree[e[0]]--;
            mx = Math.max(mx,e[0]);
            mx = Math.max(mx,e[1]);
        }
        
        for(int i = 0;i<=MAX;i++){
            if(degree[i]<=-2){                
                start = i;
                break;
            }
        }
        return start;
    }
    public int[] solution(int[][] edges) {
        int start = init(edges);
        
        int[] ans = new int[4];
        ans[0] = start;
        
        for(int s : graph[start]){
            if(chk[s])continue;
            ans[checkGraph(s)]++;
        }
        return ans;
    }
}