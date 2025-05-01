import java.io.*;
import java.util.*;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M;

    public static int[] tmp;
    public static StringBuilder result;


    public static void solve() throws Exception {
        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input);

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        tmp = new int[M];
        result = new StringBuilder();

        dfs(0);

        System.out.println(result);
    }

    public static void dfs(int cnt) {
        if (cnt == tmp.length) {
            for (int v : tmp) {
                result.append(v).append(' ');
            }
            result.append('\n');
            return;
        }
        for (int i = 1; i <= N; i++) {
            tmp[cnt] = i;
            dfs(cnt + 1);
        }
    }

    public static void main(String[] args) throws Exception {
        solve();
    }
}
