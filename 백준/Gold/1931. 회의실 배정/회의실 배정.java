import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;


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


    public static void init() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int start, end;
        pq = new PriorityQueue<>(new Comparator<meeting>() {
            public int compare(meeting o1, meeting o2) {
                if (o1.end == o2.end) {
                    return Integer.compare(o1.start, o2.start);
                }
                return Integer.compare(o1.end, o2.end);
            }
        });
        for (int i = 0; i < n; i++) {
            start = sc.nextInt();
            end = sc.nextInt();
            pq.offer(new meeting(start, end));
        }


    }

    public static void solve() {
        int ans = 0;
        meeting tmp = new meeting(-1, -1);

        while (!pq.isEmpty()){
            meeting m = pq.poll();
            if (m.start < tmp.end) {
                continue;
            }
            ans++;
            tmp = m;
        }
        System.out.println(ans);
    }


    public static void main(String[] args) {
        init();
        solve();
    }
}
