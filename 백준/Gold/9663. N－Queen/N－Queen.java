
import java.io.*;
import java.util.*;

public class Main {
    static int n,cnt;
    static int[] columns;
    static BufferedReader br;

    static void init() throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in));
        cnt = 0;
        columns = new int[17];
        n = Integer.parseInt(br.readLine());
    }

    static void solve() {
        dfs(0,0);
        System.out.println(cnt);
    }

    static boolean checkColumn(int i, int c){
        for (int j = 0; j < i; j++) {
            if (columns[j] != c && Math.abs(columns[j] - c) != Math.abs(j - i)) continue;
            return false;
        }
        return true;
    }

    static void dfs(int i, int c){
        if(i==n) {
            cnt++;
            return;
        }
        if(c == n) return;
        if(checkColumn(i,c)){
            columns[i] = c;
            dfs(i+1,0);
        }
        dfs(i,c+1);

    }
    public static void main(String[] args) throws Exception {
        init();
        solve();
    }


}