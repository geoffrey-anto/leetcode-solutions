# Burst Balloons

## Leetcode Link: [Burst Balloons](https://leetcode.com/problems/burst-balloons/)
### Language: C++

```cpp
class Solution {
public:
    // int f(int i, int j, vector<int>& nums, int n, vector<vector<int>> &dp) {
    //     if(i == j) {
    //         return 0;
    //     }

    //     if(dp[i][j] != -1) {
    //         return dp[i][j];
    //     }

    //     int mx = 0;

    //     for(int balloon=i; balloon<j; balloon++) {
    //         int res = nums[i-1] * nums[balloon] * nums[j] + f(i, balloon, nums, n, dp) + f(balloon+1, j, nums, n, dp);

    //         mx = max(mx, res);
    //     }

    //     return dp[i][j] = mx;
    // }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=n-1; i>=1; i--) {
            for(int j=i+1; j<n; j++) {
                int mx = 0;

                for(int balloon=i; balloon<j; balloon++) {
                    int res = nums[i-1] * nums[balloon] * nums[j] + dp[i][balloon] + dp[balloon+1][j];

                    if(res > mx) {
                        mx = res;
                    }
                }

                dp[i][j] = mx;
            }
        }

        return dp[1][n-1];
    }
};```



