import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static BufferedReader br;
    public static StringTokenizer st;
    public static int[][] board;
    public static int n;
    public static int[] dr;
    public static int[] dc;

    private static class Answer {
        int winner;
        int r;
        int c;

        public Answer(int winner, int r, int c) {
            this.winner = winner;
            this.r = r;
            this.c = c;
        }
    }

    private static void init() throws Exception {
        n = 19;
        board = new int[n][n];
        br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dr = new int[]{0, 1, 1, -1};
        dc = new int[]{1, 0, 1, 1};
    }

    private static boolean oob(int r, int c) {
        return r < 0 || r >= n || c < 0 || c >= n;
    }

    private static Answer traverse(int cr, int cc, int d, int color) {
        int pr = cr - dr[d], pc = cc - dc[d];
        if (!oob(pr, pc) && board[pr][pc] == color) return null;

        int r = cr, c = cc;
        int count = 0;
        while (!oob(r, c) && board[r][c] == color) {
            count++;
            if (count > 5) return null;
            r += dr[d];
            c += dc[d];
        }
        if (count == 5) {
            return new Answer(color, cr + 1, cc + 1);
        }
        return null;
    }

    private static void solve() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) continue;
                int color = board[i][j];
                for (int d = 0; d < 4; d++) {
                    Answer ans = traverse(i, j, d, color);
                    if (ans != null) {
                        System.out.println(ans.winner);
                        System.out.println(ans.r + " " + ans.c);
                        return;
                    }
                }
            }
        }
        System.out.println(0);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
