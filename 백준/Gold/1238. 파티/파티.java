import java.io.*;
import java.util.*;

public class Main{
	static int N;
	static int M;
	static int x;
	
	static ArrayList<Path>[] adj;
	static ArrayList<Path>[] backAdj;
	static PriorityQueue<Path> pq;
	static int backDist[];
	static int goDist[];
	static int ans;
	static final int INF = 987654321;
	static class Path implements Comparable<Path>{
		public int dest;
		public int dist;
		public Path(int dest,int dist){
			this.dest = dest;
			this.dist = dist;
		}
		
		@Override
		public int compareTo(Path p) {
			Integer w = this.dist;
			return w.compareTo(p.dist);
		}
	}
	static void init() throws Exception{
		BufferedReader br = new BufferedReader(
				new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		x--;
		pq = new PriorityQueue<>();
		adj = new ArrayList[N];
		backAdj = new ArrayList[N];
		backDist = new int[N];
		goDist = new int[N];
		for(int i=0;i<N;i++) {
			adj[i]=new ArrayList<>();
			backAdj[i]=new ArrayList<>();
			backDist[i] = INF;
			goDist[i] = INF;
		}
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int src = Integer.parseInt(st.nextToken());
			int dest =  Integer.parseInt(st.nextToken());
			int dist = Integer.parseInt(st.nextToken());
			src--;
			dest--;
			adj[src].add(new Path(dest, dist));
			backAdj[dest].add(new Path(src, dist));
			
		}
		
		
	}
	
	static void solve() {
		backDist[x]=0;
		pq.offer(new Path(x,0));
		while(!pq.isEmpty()) {
			Path cur = pq.poll();
			for(Path p: adj[cur.dest]) {
				if( backDist[cur.dest]+p.dist > backDist[p.dest])continue;
				backDist[p.dest] = backDist[cur.dest]+p.dist;
				pq.offer(p);
			}
		}
		goDist[x]=0;
		pq.offer(new Path(x,0));
		while(!pq.isEmpty()) {
			Path cur = pq.poll();
			for(Path p: backAdj[cur.dest]) {
				if( goDist[cur.dest]+p.dist > goDist[p.dest])continue;
				goDist[p.dest] = goDist[cur.dest]+p.dist;
				pq.offer(p);
			}
		}
		for(int i=0;i<N;i++) 
			ans = Math.max(ans,goDist[i]+backDist[i]);
	
		System.out.println(ans);
		
	}
	public static void main(String[] args) throws Exception{
		//------여기에 솔루션 코드를 작성하세요.------------
	
		init();
		solve();
	}
}