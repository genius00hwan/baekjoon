import java.io.*;
import java.util.*;

public class Main{
	static int[] arr;
	static int n;
	static int s;
	static int ans;
	static void init() throws Exception{
		BufferedReader br = new BufferedReader(
				new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		s = Integer.parseInt(st.nextToken());
		arr = new int[n];
		st = new StringTokenizer(br.readLine());

		for(int i=0;i<n;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		ans = 0;
		
	}
	static void dfs(int idx, int sum) {
		if(idx>=n) {
			return;
		}
		if(sum+arr[idx]==s) {
			ans++;
		}
		dfs(idx+1, sum+arr[idx]);
		dfs(idx+1,sum);

	}
	public static void main(String[] args) throws Exception {
		init();
		dfs(0,0);
		System.out.println(ans);
	}
}