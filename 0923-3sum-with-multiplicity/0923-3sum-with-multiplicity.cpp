class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {

        long long MOD = 1e9 + 7;
        vector<long long> freq(101, 0);

        for(int x : arr)
            freq[x]++;

        long long ans = 0;

        for(int a = 0; a <= 100; a++) {

            for(int b = a; b <= 100; b++) {

                int c = target - a - b;

                if(c < b || c > 100)
                    continue;

                if(a == b && b == c) {

                    ans += freq[a] * (freq[a]-1) *
                           (freq[a]-2) / 6;
                }

                else if(a == b) {

                    ans += (freq[a]*(freq[a]-1)/2)
                           * freq[c];
                }

                else if(b == c) {

                    ans += freq[a] *
                           (freq[b]*(freq[b]-1)/2);
                }

                else {

                    ans += freq[a] *
                           freq[b] *
                           freq[c];
                }

                ans %= MOD;
            }
        }

        return ans;
    }
};