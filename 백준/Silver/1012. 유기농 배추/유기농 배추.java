
import java.io.*;
import java.util.*;


public class Main{
	static int T;
	static int M,N;
	static int K;
	static boolean[][]graph;
	static BufferedReader br;
	static StringTokenizer st;
	static Queue<Node> q;
	static int[]dr = {1,-1,0,0};
	static int[]dc = {0,0,1,-1};
	static int ans;
	static StringBuilder out;
	static class Node{
		public int r;
		public int c;
		public Node(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}
	static void init() throws Exception{
		st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		ans = 0;
		graph = new boolean[N][M];
		q = new ArrayDeque<>();
		for(int i=0;i<K;i++) {
			st = new StringTokenizer(br.readLine());
			
			int c = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			
			graph[r][c] = true;
		}
	}
	static boolean oob(int r, int c) {
		return r < 0 || r >= N || c < 0 || c >= M;
	}
	static void bfs(int sr, int sc) {
		q.offer(new Node(sr,sc));
		graph[sr][sc] = false;
		while(!q.isEmpty()) {
			Node cur = q.poll();
			for(int i=0;i<4;i++) {
				int nr = cur.r + dr[i];
				int nc = cur.c + dc[i];
				if(oob(nr,nc))continue;
				if(!graph[nr][nc])continue;
				q.offer(new Node(nr,nc));
				graph[nr][nc] = false;
			}
		}
	}
	static void solve() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(!graph[i][j])continue;
				bfs(i,j);
				ans++;
			}
		}
		out.append(ans);
		out.append('\n');
	}
	public static void main(String[] args) throws Exception{
		br = new BufferedReader(
				new InputStreamReader(System.in));
		
		T = Integer.parseInt(br.readLine());
		out = new StringBuilder();
		while(T-->0) {
			init();
			solve();
		}
		System.out.print(out.toString());
	}
}