import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static String criteria;
    public static String input;
    public static Stack<Character> stack;

    public static void init() throws Exception {
        input = br.readLine();
        stack = new Stack<>();
        criteria = br.readLine();
    }

    public static void solve() {
        for(char c : input.toCharArray()){
            push(c);
        }
        StringBuilder ans = new StringBuilder();
        while (!stack.isEmpty()){
            char cur = stack.pop();
            ans.append(cur);
        }
        if(ans.length()==0){
            System.out.println("FRULA");
        }
        System.out.println(ans.reverse());

    }

    public static void push(char c) {
        StringBuilder tmp= new StringBuilder();
        if (c == criteria.charAt(criteria.length() - 1) && stack.size() >= criteria.length()-1) {
            tmp.append(c);
            while (tmp.length()!=criteria.length()){
                tmp.append(stack.peek());
                stack.pop();
            }
            tmp.reverse();
            if (!tmp.toString().equals(criteria)) {
                for (char t : tmp.toString().toCharArray()) {
                    stack.push(t);
                }
            }
            return;
        }
        stack.push(c);
    }


    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}