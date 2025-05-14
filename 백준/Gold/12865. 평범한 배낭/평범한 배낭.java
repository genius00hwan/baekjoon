import java.io.*;
import java.util.*;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static int N;
    public static int K;

    public static int[][] items;
    public static int[][] mem;

    public static void init() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        items = new int[N + 1][2];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            items[i][0] = Integer.parseInt(st.nextToken());
            items[i][1] = Integer.parseInt(st.nextToken());
        }
        mem = new int[N + 1][K + 1];
    }

    public static void solve() {
        for (int i = 1; i <= N; i++) {
            int w = items[i][0];
            int v = items[i][1];
            for (int j = 1; j <= K; j++) {
                if (w > j) {
                    mem[i][j] = mem[i - 1][j];
                    continue;
                }
                mem[i][j] = Math.max(v + mem[i - 1][j - w], mem[i - 1][j]);
            }
        }

        System.out.print(mem[N][K]);
    }


    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
