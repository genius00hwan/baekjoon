import java.util.*;
import java.io.*;

public class Main{
	
	public static boolean arr[];
	public static int N, M;
	public static class Entry{
		public int gender;
		public int num;
		public Entry(int gender, int num) {
			this.gender = gender;
			this.num = num;
		}
		public void turnOnOff() {
			if(this.gender == 1) {
				maleDo();
				return;
			}
			femaleDo();
		}
		
		private void maleDo() {
			for(int i=this.num;i<=N;i+=num) {
				arr[i-1]=!arr[i-1];
			}
			
		}
		
		private void femaleDo() {
			int center = this.num - 1;
			int diff = Math.min(center, N-1-center);
			for(int i=0;i<=diff;i++) {
				if(arr[center-i]!=arr[center+i])break;
				arr[center-i] = arr[center+i] = !arr[center-i];
			}
			//StringBuilder sb = new StringBuilder();
			//for(int i=0;i<N;i++) {
			//	sb.append(arr[i]?"1 ":"0 ");
			//}
			//System.out.println(sb.toString());
		}
	}
	
	public static List<Entry> list;
	
	public static void init() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		arr = new boolean[N];
		for(int i=0;i<N;i++) {
			arr[i] = (st.nextToken().equals("1"));
		}
		M = Integer.parseInt(br.readLine());
		list = new ArrayList<>();
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int gender = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());
			list.add(new Entry(gender, num));
		}
		
	}
	
	public static void solve() {
		for(Entry e : list) {
			e.turnOnOff();
		}
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<N;i++) {
			sb.append(arr[i]?"1 ":"0 ");
            if((i+1)%20==0)
                sb.append("\n");
		}
		System.out.println(sb.toString());
	}
	public static void main(String[] args) throws Exception{
		init();
		solve();
	}

}
