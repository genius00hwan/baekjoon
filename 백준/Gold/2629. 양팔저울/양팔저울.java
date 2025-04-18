import java.io.*;
import java.util.*;

public class Main {

    static int[] w;
    static boolean[][] memo;
    static int n;
    static int[] mbs;
    static int m;

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        w = new int[31];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(st.nextToken());
        }

        m = Integer.parseInt(br.readLine());
        mbs = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            mbs[i] = Integer.parseInt(st.nextToken());
        }

        memo = new boolean[31][15001];
    }

    static void dfs(int i, int v) {
        if (i > n || memo[i][v]) {
            return;
        }
        memo[i][v] = true;

        dfs(i + 1, v); // 사용 X
        dfs(i + 1, Math.abs(v - w[i])); // 구슬쪽
        dfs(i + 1, v + w[i]); // 안 구슬쪽
    }

    public static void solve() {
        dfs(0, 0);
        StringBuilder sb = new StringBuilder();
        for (int x : mbs) {
            if (x > 15000) {
                sb.append("N ");
            } else {
                sb.append(memo[n][x] ? "Y " : "N ");
            }
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}


