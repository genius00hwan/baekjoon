import java.io.*;
import java.util.*;

public class Main {
    static int PLAYER_SIZE = 9;
    static int n;
    static int[][] power;
    static boolean[] used;
    static int[] order;
    static int ans = 0;

    static void play() {
        int score = 0;
        int cur = 0;

        for (int inning = 0; inning < n; inning++) {
            int outs = 0;
            boolean b1 = false, b2 = false, b3 = false;

            while (outs < 3) {
                int player = order[cur];
                int hit = power[inning][player];

                if (hit == 0) {
                    outs++;
                } else if (hit == 1) {
                    if (b3) score++;
                    b3 = b2;
                    b2 = b1;
                    b1 = true;
                } else if (hit == 2) {
                    if (b3) score++;
                    if (b2) score++;
                    b3 = b1;
                    b2 = true;
                    b1 = false;
                } else if (hit == 3) {
                    if (b3) score++;
                    if (b2) score++;
                    if (b1) score++;
                    b3 = true;
                    b2 = false;
                    b1 = false;
                } else {
                    if (b3) score++;
                    if (b2) score++;
                    if (b1) score++;
                    score++;
                    b1 = b2 = b3 = false;
                }

                cur = (cur + 1) % PLAYER_SIZE;
            }
        }

        ans = Math.max(ans, score);
    }

    static void solve(int pos) {
        if (pos == PLAYER_SIZE) {
            play();
            return;
        }
        if (pos == 3) {
            solve(pos + 1);
            return;
        }

        for (int p = 1; p < PLAYER_SIZE; p++) {
            if (used[p]) continue;
            used[p] = true;
            order[pos] = p;
            solve(pos + 1);
            used[p] = false;
        }
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine().trim());
        power = new int[n][9];
        used = new boolean[9];
        order = new int[9];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int p = 0; p < 9; p++) {
                power[i][p] = Integer.parseInt(st.nextToken());
            }
        }

        Arrays.fill(used, false);
        used[0] = true;
        order[3] = 0;
    }

    public static void main(String[] args) throws Exception {
        init();
        solve(0);

        System.out.println(ans);
    }
}