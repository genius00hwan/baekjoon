import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static List<Edge>[] graph;
    static int start, end;

    static class Edge {
        int src, weight;
        Edge(int to, int weight) {
            this.src = to;
            this.weight = weight;
        }
    }

    static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) graph[i] = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to   = Integer.parseInt(st.nextToken());
            int w    = Integer.parseInt(st.nextToken());
            graph[from].add(new Edge(to, w));
            graph[to].add(new Edge(from, w));
        }

        st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());
    }

    static void solve() {
        int[] dist = new int[N + 1]; 
        Arrays.fill(dist, -1);
        dist[start] = Integer.MAX_VALUE;

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        pq.offer(new int[]{start, Integer.MAX_VALUE});

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int node = cur[0];
            int weight = cur[1];

            if (node == end) {
                System.out.println(weight);
                return;
            }

            for (Edge e : graph[node]) {
                int next = e.src;
                int nextWeight = Math.min(weight, e.weight);
                if (dist[next] < nextWeight) {
                    dist[next] = nextWeight;
                    pq.offer(new int[]{next, nextWeight});
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
