import java.io.*;
import java.util.*;

public class Main {
    static List<Integer>[] taller;
    static boolean[] visited;
    static Deque<Integer> order;
    static int n, m;

    static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        order = new ArrayDeque<>(n);
        taller = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) taller[i] = new ArrayList<>();
        visited = new boolean[n + 1];


        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            taller[a].add(b);
        }
    }

    static void dfs(int cur) {
        if (visited[cur]) return;
        visited[cur] = true;
        for (int nxt : taller[cur]) dfs(nxt);
        order.addFirst(cur); // C++ push_front와 동일 효과
    }

    static void solve() {
        for (int i = 1; i <= n; i++) if (!visited[i]) dfs(i);

        StringBuilder sb = new StringBuilder();
        while (!order.isEmpty()) sb.append(order.pollFirst()).append(' ');
        System.out.print(sb);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
