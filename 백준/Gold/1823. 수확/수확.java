import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] rice;
    static int[][] dp;

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        rice = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            rice[i] = Integer.parseInt(br.readLine());
        }

        dp = new int[N + 2][N + 2];
    }

    public static void solve() {
        for (int len = 1; len <= N; len++) {
            for (int l = 1; l + len - 1 <= N; l++) {
                int r = l + len - 1;
                int step = N - (r - l);
                dp[l][r] = Math.max(
                    rice[l] * step + dp[l + 1][r],
                    rice[r] * step + dp[l][r - 1]
                );
            }
        }
        System.out.println(dp[1][N]);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}