import java.io.*;
import java.util.*;


public class Main {
    public static int n;
    public static PriorityQueue<meeting> pq;

    public static class meeting {
        public int start;
        public int end;

        public meeting(int start, int end) {
            this.start = start;
            this.end = end;
        }

    }


    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        int start, end;

        pq = new PriorityQueue<>((o1, o2) -> {
            if (o1.end == o2.end) {
                return Integer.compare(o1.start, o2.start);
            }
            return Integer.compare(o1.end, o2.end);
        });
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            start = Integer.parseInt(input[0]);
            end = Integer.parseInt(input[1]);
            pq.offer(new meeting(start, end));
        }


    }

    public static void solve() {
        int ans = 0;
        meeting tmp = new meeting(-1, -1);

        while (!pq.isEmpty()) {
            meeting m = pq.poll();
            if (m.start < tmp.end) {
                continue;
            }
            ans++;
            tmp = m;
        }
        System.out.println(ans);
    }


    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
