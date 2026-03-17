#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        // Count frequency
        for(int num : nums) {
            freq[num]++;
        }
        
        // Bucket array
        vector<vector<int>> bucket(nums.size() + 1);
        
        for(auto &p : freq) {
            int number = p.first;
            int count = p.second;
            bucket[count].push_back(number);
        }
        
        vector<int> result;
        
        // Traverse from highest frequency
        for(int i = bucket.size() - 1; i >= 0 && result.size() < k; i--) {
            for(int num : bucket[i]) {
                result.push_back(num);
                if(result.size() == k)
                    break;
            }
        }
        
        return result;
    }
};