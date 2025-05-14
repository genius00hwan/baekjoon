import java.io.*;
import java.util.*;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static String input;
    public static int[] parallel;
    public static int[] vertical;
    public static int[] slash;
    public static int[] bingo;

    public static int[] seq;

    public static void init() throws Exception {
        parallel = new int[26];
        vertical = new int[26];
        slash = new int[26]; // i==j-> 1 i+j==4-> 2

        for (int i = 0; i < 5; i++) {
            input = br.readLine();
            String[] arr = input.split(" ");
            for (int j = 0; j < 5; j++) {
                int v = Integer.parseInt(arr[j]);
                parallel[v] = i;
                vertical[v] = j;
                if (i == j && i + j == 4) {
                    slash[v] = -1;
                } else if (i == j) {
                    slash[v] = 1;
                } else if (i + j == 4) {
                    slash[v] = 2;
                }
            }
        }
        seq = new int[26];
        for (int i = 0; i < 5; i++) {
            input = br.readLine();
            String[] arr = input.split(" ");
            for (int j = 0; j < 5; j++) {
                seq[(i * 5) + j] = Integer.parseInt(arr[j]);
            }
        }


    }

    public static void solve() throws Exception {
        bingo = new int[12];
        int ans = 0;
        for (int v : seq) {
            ans++;

            if (slash[v] != 0) {
                if(slash[v]==-1){
                    bingo[10]++;
                    bingo[11]++;
                }
                else{
                    bingo[9 + slash[v]]++;    
                }
                
            }
            bingo[parallel[v]]++;
            bingo[5 + vertical[v]]++;
            int cnt = 0;
            for (int b : bingo) {
                if (b >= 5) {
                    cnt++;
                }
            }
            if (cnt >= 3) {
                System.out.println(ans);
                break;
            }
        }
    }


    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
