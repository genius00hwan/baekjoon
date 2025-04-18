import java.io.*;
import java.util.*;

public class Main {

    public static int n;
    public static long k;

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        k = Long.parseLong(br.readLine());
    }

    public static void solve() {
        long l = 1, r = k;
        long ans = 0;

        while (l <= r) {
            long mid = (l + r) / 2;

            if (count(mid) >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        System.out.println(ans);
    }

    static long count(long x) {
        long cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += Math.min(x / i, n);
        }
        return cnt;
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
