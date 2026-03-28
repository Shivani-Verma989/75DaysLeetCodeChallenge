class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        
        int left = 0, maxFreq = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            // Update frequency
            freq[s[right] - 'A']++;
            
            // Track max frequency in current window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            
            // If invalid window, shrink it
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            
            // Update answer
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};