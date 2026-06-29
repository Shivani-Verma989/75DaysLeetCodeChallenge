class Solution {

    public int shipWithinDays(int[] weights, int days) {

        int low = 0;
        int high = 0;

        // Find minimum and maximum possible capacity
        for (int weight : weights) {
            low = Math.max(low, weight);
            high += weight;
        }

        // Binary Search
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

    // Check if the given capacity is sufficient
    private boolean canShip(int[] weights, int days, int capacity) {

        int daysNeeded = 1;
        int currentLoad = 0;

        for (int weight : weights) {

            if (currentLoad + weight > capacity) {
                daysNeeded++;
                currentLoad = 0;
            }

            currentLoad += weight;
        }

        return daysNeeded <= days;
    }
}
      
     