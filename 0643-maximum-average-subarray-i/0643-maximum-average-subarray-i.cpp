class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Find sum of first window
        double windowSum = 0;
        for(int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        
        double maxSum = windowSum;
        
        // Step 2: Slide the window
        for(int i = k; i < n; i++) {
            windowSum += nums[i];      // add next element
            windowSum -= nums[i - k];  // remove first element of previous window
            
            maxSum = max(maxSum, windowSum);
        }
        
        // Step 3: Return maximum average
        return maxSum / k;
    }
};