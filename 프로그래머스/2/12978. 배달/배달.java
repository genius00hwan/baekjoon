import java.util.*;

class Solution {
    int n;
    int INF = Integer.MAX_VALUE;
    public class Edge implements Comparable<Edge>{
        int dest; // 목적지
        int cost; // 비용
        public Edge(int d,int c){
            this.dest = d;
            this.cost = c;
        }
        public int compareTo(Edge e){
            return Integer.compare(this.cost, e.cost);
        }
    }
    List<Edge>[] graph;
    int[] dist;
    public void init(int N, int[][] road){
        graph = new List[N];
        dist = new int[N];
        
        for(int i=0;i<N;i++){
            graph[i] = new ArrayList();
        }
        for(int i=0;i<road.length;i++){
            int src = road[i][0]-1;
            int dest = road[i][1]-1;
            int cost = road[i][2];
            graph[src].add(new Edge(dest,cost));
            graph[dest].add(new Edge(src,cost));
        }
        for(int i=0;i<N;i++){
            dist[i]=INF;
        }
        
    }
    
    public void djikstra(){
        PriorityQueue<Edge> pq = new PriorityQueue();
        pq.offer(new Edge(0,0));
        dist[0] = 0;
        while(!pq.isEmpty()){
            Edge cur = pq.poll();
            for(Edge e : graph[cur.dest]){
                if(dist[e.dest]<=cur.cost + e.cost)continue;
                dist[e.dest]=cur.cost + e.cost;
                pq.offer(new Edge(e.dest,dist[e.dest]));
            }
        }
        
    }
    public int solution(int N, int[][] road, int K) {
        init(N,road);
        int ans = 0;
        djikstra();
        for(int i=0;i<N;i++){
            if(dist[i]>K)continue;
            ans++;
        }
        return ans;
    }
}