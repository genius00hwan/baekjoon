import java.io.*;
import java.util.*;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int[][] mem;
    public static int[][] subject;
    public static int N;
    public static int K;

    public static void init() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        subject = new int[K + 1][2];
        for (int i = 1; i <= K; i++) {
            st = new StringTokenizer(br.readLine());
            subject[i][0] = Integer.parseInt(st.nextToken());
            subject[i][1] = Integer.parseInt(st.nextToken());
        }
        mem = new int[K + 1][N + 1];
    }

    public static void solve() {
        for (int i = 1; i <= K; i++) {
            int value = subject[i][0];
            int cost = subject[i][1];
            for (int j = 1; j <= N; j++) {
                if (j < cost) {
                    mem[i][j] = mem[i-1][j];
                    continue;
                }
                mem[i][j] = Math.max(mem[i-1][j-cost]+value,mem[i-1][j]);
            }
        }

        System.out.print(mem[K][N]);
    }


    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
