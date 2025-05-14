import java.io.*;
import java.util.*;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int[][] mem;
    public static int[][] blocks;
    public static int N, M, H;
    public static int MOD = 10007;


    public static void init() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        blocks = new int[N + 1][M + 1];
        mem = new int[N + 1][H + 1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int idx = 0;
            while (st.hasMoreTokens()) {
                blocks[i][idx++] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i <= N; i++) {
            mem[i][0] = 1;
        }
    }

    public static void solve() {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= H; j++) {
                for (int b : blocks[i]) {
                    if (b==0||b > j) {
                        continue;
                    }
                    mem[i][j] = (mem[i][j]+mem[i - 1][j - b])%MOD;
                }
                mem[i][j] = (mem[i][j]+mem[i-1][j])%MOD;
            }
        }

        System.out.print(mem[N][H]);
    }


    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
