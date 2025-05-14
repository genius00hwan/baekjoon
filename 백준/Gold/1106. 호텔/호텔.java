import java.io.*;
import java.util.*;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int[] mem; // 비용, 가치
    public static int[][] cost;
    public static int N;
    public static int C;

    public static void init() throws Exception {
        ;
        StringTokenizer st = new StringTokenizer(br.readLine());
        C = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        cost = new int[N + 1][2];
        mem = new int[C + 101];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            cost[i][0] = Integer.parseInt(st.nextToken()); // 비용
            cost[i][1] = Integer.parseInt(st.nextToken()); // 가치
        }
        Arrays.fill(mem, 987654321);
    }

    public static void solve() {
        mem[0] = 0;
        for (int i = 1; i <= N; i++) {
            int c = cost[i][0];
            int v = cost[i][1];
            for (int j = v; j <= C + 100; j++) {
                mem[j] = Math.min(mem[j], mem[j - v] + c);
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int i = C; i < C + 101; i++) {
            ans = Math.min(ans, mem[i]);
        }
        System.out.print(ans);

    }


    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
