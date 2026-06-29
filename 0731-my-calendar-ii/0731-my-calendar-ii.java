import java.util.*;

class MyCalendarTwo {

    List<int[]> bookings;
    List<int[]> overlaps;

    public MyCalendarTwo() {
        bookings = new ArrayList<>();
        overlaps = new ArrayList<>();
    }

    public boolean book(int start, int end) {

        for (int[] overlap : overlaps) {
            if (start < overlap[1] && end > overlap[0]) {
                return false;
            }
        }
        for (int[] booking : bookings) {
            if (start < booking[1] && end > booking[0]) {

                int overlapStart = Math.max(start, booking[0]);
                int overlapEnd = Math.min(end, booking[1]);

                overlaps.add(new int[]{overlapStart, overlapEnd});
            }
        }
        bookings.add(new int[]{start, end});

        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(startTime,endTime);
 */