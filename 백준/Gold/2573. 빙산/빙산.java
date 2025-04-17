import java.io.*;
import java.util.*;

class Main {

    public static int[][] graph;
    public static int n, m;
    public static int[] dr;
    public static int[] dc;
    public static boolean[][] chk;

    public static class Node {
        int r;
        int c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input);
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        graph = new int[n][m];
        for (int i = 0; i < n; i++) {
            input = br.readLine();
            st = new StringTokenizer(input);
            for (int j = 0; j < m; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dr = new int[]{0, 0, 1, -1};
        dc = new int[]{1, -1, 0, 0};
        chk = new boolean[n][m];
    }

    public static boolean oob(int r, int c) {
        return (r < 0 || r >= n || c < 0 || c >= m);
    }

    public static int melt(int r, int c) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (oob(nr, nc)) {
                continue;
            }
            if (graph[nr][nc] == 0) {
                cnt++;
            }
        }
        return Math.max(graph[r][c] - cnt, 0);
    }

    public static void takeAYear() {
        int[][] ng = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ng[i][j] = melt(i, j);
            }
        }
        graph = ng;

//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                System.out.print(graph[i][j] + " ");
//            }
//            System.out.println();
//        }
//        System.out.println();
    }

    public static int check() {
        boolean flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 0) {
                    continue;
                }
                if (!chk[i][j]) {
                    if (!flag) {
                        bfs(i, j);
                        flag = true;
                    } else {
                        return -1; // stop
                    }
                }
            }
        }
        if (!flag) {
            return 0; // 분리 안됨
        }
        return 1; // 1년 더 보셈
    }

    public static void bfs(int r, int c) {
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(r, c));
        chk[r][c] = true;
        while (!q.isEmpty()) {
            Node cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];
                if (oob(nr, nc)) {
                    continue;
                }
                if (chk[nr][nc]) {
                    continue;
                }
                if(graph[nr][nc]==0){
                    continue;
                }
                q.offer(new Node(nr, nc));
                chk[nr][nc] = true;
            }
        }
    }

    public static void clear() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                chk[i][j] = false;
            }
        }
    }

    public static void solve() {
        int cnt = 0;
        int flag;
        while ((flag = check()) == 1) {
            takeAYear();
            cnt++;
            clear();
        }
        if (flag == 0) {
            System.out.println(0);
        } else {
            System.out.println(cnt);
        }
    }


    public static void main(String[] args) throws Exception {
        init();
        solve();
    }


}

