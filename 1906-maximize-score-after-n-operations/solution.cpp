class Solution {
public:
    vector<int> dp;
    // basically to maintain the already taken idxs maintain a bitmask
    // so at set bit i means the pos of bit j is taken in gcd
    // so 7 * 2 == 14 == 1 << 14 == 16000ish
    int f(int c, int mask, vector<int>& nums, int n, int lim) {
        if(c > lim) {
            return 0;
        }
        
        if(dp[mask] != -1) {
            return dp[mask];
        }

        for(int i=0; i<n; i++) {
            if((mask & (1 << i))) {
                continue;
            }
            
            for(int j=i+1; j<n; j++) {
                if((mask & (1 << j))) {
                    continue;
                }

                int nm = (1 << i) | (1 << j) | mask;

                int a = ((c) * __gcd(nums[i], nums[j])) + f(c+1, nm, nums, n, lim);

                dp[mask] = max(dp[mask], a);
            }
        }

        return dp[mask];
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(16384, -1);

        return f(1, 0, nums, n, n/2);
    }
};
