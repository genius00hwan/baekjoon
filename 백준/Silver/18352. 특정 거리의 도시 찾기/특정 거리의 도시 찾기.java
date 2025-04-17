import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;


class Main {
    public static int n, m, k, x;
    public static List<Integer>[] edges;
    public static int[] dist;
    public static Queue<Integer> q;

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input);
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        edges = new ArrayList[n + 2];
        for (int i = 0; i < n+2; i++) {
            edges[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            input = br.readLine();
            st = new StringTokenizer(input);
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            edges[a].add(b);
        }
        dist = new int[n + 2];
        q = new ArrayDeque<>();
        for (int i = 0; i < n + 2; i++) {
            dist[i] = -1;
        }
    }

    public static void solve() {
        dist[x] = 0;
        q.offer(x);
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int v : edges[cur]) {
                if (dist[v] != -1) {
                    continue;
                }
                dist[v] = dist[cur] + 1;
                q.offer(v);
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == k) {
                System.out.println(i);
                cnt++;
            }
        }
        if (cnt == 0) {
            System.out.println(-1);
        }
    }


    public static void main(String[] args) throws Exception {
        init();
        solve();
    }

}

