import java.util.*;

class Solution {
    static class Homework {
        String name;
        int start;
        int playtime;

        Homework(String name, String start, String playtime) {
            this.name = name;
            this.start = toMinutes(start);
            this.playtime = Integer.parseInt(playtime);
        }

        static int toMinutes(String time) {
            String[] parts = time.split(":");
            return Integer.parseInt(parts[0]) * 60 + Integer.parseInt(parts[1]);
        }
    }

    public String[] solution(String[][] plans) {
        List<String> answer = new ArrayList<>();
        Stack<Homework> stack = new Stack<>();

        // 1. 정렬
        Arrays.sort(plans, Comparator.comparing(p -> Homework.toMinutes(p[1])));

        for (int i = 0; i < plans.length; i++) {
            Homework cur = new Homework(plans[i][0], plans[i][1], plans[i][2]);
            int curStart = cur.start;

            // 다음 과제가 있다면 종료 시각 계산
            int nextStart = (i < plans.length - 1) ? Homework.toMinutes(plans[i + 1][1]) : Integer.MAX_VALUE;

            int timeAvailable = nextStart - curStart;

            // 현재 과제를 바로 할 수 있으면 수행
            if (cur.playtime <= timeAvailable) {
                answer.add(cur.name);
                timeAvailable -= cur.playtime;

                // 남은 시간 동안 스택에서 과제 재개
                while (!stack.isEmpty() && timeAvailable > 0) {
                    Homework paused = stack.pop();
                    if (paused.playtime <= timeAvailable) {
                        answer.add(paused.name);
                        timeAvailable -= paused.playtime;
                    } else {
                        paused.playtime -= timeAvailable;
                        stack.push(paused);
                        break;
                    }
                }
            } else {
                // 다 못하면 스택에 push
                cur.playtime -= timeAvailable;
                stack.push(cur);
            }
        }

        // 스택에 남은 거 마저 정리
        while (!stack.isEmpty()) {
            answer.add(stack.pop().name);
        }

        return answer.toArray(new String[0]);
    }
}
