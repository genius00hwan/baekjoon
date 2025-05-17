import java.util.*;
class Solution {
    public int[] dr = {0,1,0,-1};
    public int[] dc = {1,0,-1,0};
    public char[][] graph;
    public boolean[][] chk;
    public class node{
        public int r;
        public int c;
        public node(int r,int c){
            this.r = r;
            this.c = c;
        }
    }
    public List<node> eraseList;
    int N,M;
    public boolean oob(int r, int c){
        return (r<0||r>=N+2||c<0||c>=M+2);
    }

    public void take(){
        for(node n : eraseList){
            graph[n.r][n.c] = '?';
        }
        eraseList = new ArrayList();
    }
    public void getEdge(char target,int r, int c){
        chk[r][c] = true;
        for(int i=0;i<4;i++){
            int nr = dr[i]+r;
            int nc = dc[i]+c;
            if(oob(nr,nc))continue;
            if(graph[nr][nc]!=target)continue;
            eraseList.add(new node(nr,nc));
        }
        for(int i=0;i<4;i++){
            int nr = dr[i]+r;
            int nc = dc[i]+c;
            if(oob(nr,nc))continue;
            if(graph[nr][nc]!='?')continue;
            if(chk[nr][nc])continue;
            getEdge(target,nr,nc);
        }
    }
    public void getAny(char target){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(graph[i][j]!=target)continue;
                eraseList.add(new node(i,j));
            }
        }
    }
    public int count(){
        int cnt = 0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(graph[i][j] == '?')continue;
                cnt++;
            }
        }
        return cnt;
    }
    
    public void print(){
        for(int i=0;i<=N+1;i++){
            for(int j=0;j<=M+1;j++){
                System.out.print(graph[i][j]);
            }System.out.println();
        }
    }
    public int solution(String[] storage, String[] requests) {
        N = storage.length;
        M = storage[0].length();
        graph = new char[N+2][M+2];
        chk = new boolean[N+2][M+2];
        eraseList = new ArrayList();
        
        for(int i=0;i<=M+1;i++){
            graph[0][i]='?';
            graph[N+1][i]='?';
        }
        for(int i=0;i<=N+1;i++){
            graph[i][0]='?';
            graph[i][M+1]='?';
        }
        int r = 1;
        for(String str : storage){
            int c = 1;
            for(char obj : str.toCharArray()){
                graph[r][c++] = obj;
            }
            r++;
        }
        for(String req : requests){
            if(req.length() == 1){
                getEdge(req.charAt(0),0,0);
                chk = new boolean[N+2][M+2];
            }else{
                getAny(req.charAt(0));
            }
            take();
            // System.out.println(req);
            // print();
        }
        int answer = count();
        
        return answer;
    }
}