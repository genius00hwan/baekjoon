import java.util.*;
import java.util.Scanner;

public class Main {
    public static int T, W;
    public static int[][][] mem;
    public static int input[];


    public static void init() {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        W = sc.nextInt();
        mem = new int[T + 2][W + 2][2];
        input = new int[T];
        int one = 0, two = 0;
        for (int i = 0; i < T; i++) {
            input[i] = sc.nextInt();
            if (input[i] == 1) {
                one++;
                mem[i + 1][0][0] = one;
            }
            if (input[i] == 2) {
                two++;
                mem[i + 1][1][1] = two;
            }

        }

    }

    public static void solve() {
        for (int t = 1; t <= T; t++) {
            for (int n = 1; n <= Math.min(t, W); n++) {
                mem[t][n][0] = Math.max(mem[t - 1][n - 1][1], mem[t - 1][n][0]);
                mem[t][n][1] = Math.max(mem[t - 1][n - 1][0], mem[t - 1][n][1]);

                mem[t][n][input[t - 1] - 1]++;
            }
        }

        int ans = 0;
        for (int i = 0; i <= W; i++) {
            ans = Math.max(ans, Math.max(mem[T][i][0], mem[T][i][1]));
        }
        System.out.println(ans);
    }


    public static void main(String[] args) {
        init();
        solve();
    }
}
