import java.io.*;
import java.util.*;

public class Main {
    public static int ans;
    public static BufferedReader br;
    public static int R;
    public static int C;
    public static boolean[][] graph;
    public static int[] dr;


    public static boolean oob(int r, int c) {
        return r < 0 || r >= R || c < 0 || c >= C;
    }

    public static boolean dfs(int r, int c) {

        for(int i=0;i<3;i++){
            int nr = r+dr[i];
            int nc = c+1;
            if(oob(nr,nc))continue;
            if(!graph[nr][nc])continue;
            if(nc==C-1){
//                print();
                ans++;
                return true;
            }
            graph[nr][nc] = false;
            if(dfs(nr,nc)) return true;
        }
        return false;
    }
//    public static void print() {
//        for (int i = 0; i < R; i++) {
//            for (int j = 0; j < C; j++) {
//                System.out.print(graph[i][j] ? 0 : 1);
//            }
//            System.out.println();
//        }
//        System.out.println();
//    }
    public static void solve() {

        for(int i=0;i<R;i++){
            dfs(i,0);
        }
        System.out.println(ans);
    }


    public static void init() throws Exception {

//        ans = new StringBuilder();
        ans = 0;
        br = new BufferedReader(new InputStreamReader(System.in));
        dr = new int[]{-1, 0, 1};

        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        graph = new boolean[R][C];
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            String line = st.nextToken();
            for (int j = 0; j < C; j++) {
                graph[i][j] = line.charAt(j) == '.';
            }
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}