import java.io.*;
import java.util.*;

class Main {

    public static int n, k;

    public static Queue<Integer> q;
    public static int[] order;
    public static int[] prev;
    public static final int MAX = 100000;


    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input);
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        q = new ArrayDeque<>();
        order = new int[MAX + 1];
        prev = new int[MAX + 1];
    }

    public static void solve() {
        q.offer(n);
        prev[n] = -1;
        order[n] = 1;
        while (!q.isEmpty()) {
            int cur = q.poll();
            if (cur == k) {
                break;
            }
            if (cur - 1 >= 0 && order[cur - 1] == 0) {
                order[cur - 1] = order[cur] + 1;
                prev[cur - 1] = cur;
                q.offer(cur - 1);
            }
            if (cur + 1 <= MAX && order[cur + 1] == 0) {
                order[cur + 1] = order[cur] + 1;
                prev[cur + 1] = cur;
                q.offer(cur + 1);
            }
            if (cur * 2 <= MAX && order[2 * cur] == 0) {
                order[2 * cur] = order[cur] + 1;
                prev[2 * cur] = cur;
                q.offer(2 * cur);
            }
        }

        System.out.println(order[k]-1);

        Stack<Integer> path = new Stack<>();
        for (int i = k; i != -1; i = prev[i]) {
            path.push(i);
        }
        while (!path.isEmpty()) {
            System.out.print(path.pop() + " ");
        }
    }


    public static void main(String[] args) throws Exception {
        init();
        solve();
    }


}

