# Visit Array Positions To Maximize Score

## Leetcode Link: [Visit Array Positions To Maximize Score](https://leetcode.com/problems/visit-array-positions-to-maximize-score/)
### Language: C++

```cpp
class Solution {
public:
    int getParity(int n) {
        return (n % 2 != 0);
    }

    long long f(int idx, int prev, vector<int>& nums, int x, int n, vector<vector<long long>> &dp) {
        if(idx == n) {
            return 0;
        }

        if(dp[idx][prev] != -1) return dp[idx][prev];

        long long pick = -1e13;
        long long notpick = -1e13;

        if(getParity(nums[idx])) {
            if(prev == 1) {
                pick = nums[idx] + f(idx+1, getParity(nums[idx]), nums, x, n, dp); 
            } else {
                pick = nums[idx] - x + f(idx+1, getParity(nums[idx]), nums, x, n, dp); 
            }
        } else {
            if(!prev) {
                pick = nums[idx] + f(idx+1, getParity(nums[idx]), nums, x, n, dp); 
            } else {
                pick = nums[idx] - x + f(idx+1, getParity(nums[idx]), nums, x, n, dp); 
            }
        }

        notpick = 0 + f(idx+1, prev, nums, x, n, dp);


        return dp[idx][prev] = max(pick, notpick);
    }


    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long> (2, -1));
        return f(0, (nums[0]%2 != 0), nums, x, n, dp);
    }
};```



