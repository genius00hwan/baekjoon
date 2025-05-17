import java.util.*;

class Solution {
    public List<Integer>[] graph;
    public boolean[] chk;
    public void init(int n, int[][] con){
        graph = new List[n];
        chk = new boolean[n];

        for(int i=0;i<n;i++){
            graph[i] = new ArrayList();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(con[i][j]==1){
                    graph[i].add(j);
                }
            }
        }
    }
    public void bfs(int start){
        Queue<Integer>q = new ArrayDeque();
        q.offer(start);
        chk[start]=true;
        while(!q.isEmpty()){
            int cur = q.poll();
            for(int v : graph[cur]){
                if(chk[v])continue;
                q.offer(v);
                chk[v]=true;
            }
        }
    }
    public int solution(int n, int[][] computers) {
        int ans = 0;
        init(n,computers);
        for(int i=0;i<n;i++){
            if(chk[i])continue;
            bfs(i);
            ans++;
        }
        return ans;
    }
}