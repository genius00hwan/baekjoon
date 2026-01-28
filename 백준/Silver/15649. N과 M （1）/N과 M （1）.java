import java.io.*;
import java.util.*;

public class Main {
    public static int n, m;
    public static boolean[] chk;
    public static int[] ans;
    public static StringBuilder sb;

    public static void dfs(int cnt) {
        if (cnt == m) {
            for (int i = 0; i < m; i++) {
                sb.append(ans[i]);
                sb.append(" ");
            }
            sb.append("\n");
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!chk[i]) {
                chk[i] = true;
                ans[cnt] = i;
                dfs(cnt + 1);
                chk[i] = false;
            }
        }
    }

    public static void solve() {
        dfs(0);
        System.out.print(sb);
    }

    public static void init() throws Exception {
        sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        ans = new int[m + 1];
        chk = new boolean[n + 1];
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}