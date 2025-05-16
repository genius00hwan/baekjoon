import java.util.*;


class Solution {
    public int solution(String[][] book_time) {
        int[] booking_list = new int[1440 + 10]; // 10분 청소시간 고려

        for (String[] time : book_time) {
            int start = toMinutes(time[0]);
            int end = toMinutes(time[1]) + 10; // 청소 시간 포함
            for (int t = start; t < end; t++) {
                booking_list[t]++;
            }
        }

        int maxRoom = 0;
        for (int b : booking_list) {
            maxRoom = Math.max(maxRoom, b);
        }
        return maxRoom;
    }

    private int toMinutes(String time) {
        String[] parts = time.split(":");
        return Integer.parseInt(parts[0]) * 60 + Integer.parseInt(parts[1]);
    }
}