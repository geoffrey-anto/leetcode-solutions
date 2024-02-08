# Number Of Dice Rolls With Target Sum

## Leetcode Link: [Number Of Dice Rolls With Target Sum](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/)
### Language: C++

```cpp
class Solution {
    long long MOD = 1e9 + 7;
public:
    int f(int n, int k, int target, vector<vector<int>> &dp) {
        if (n == 0 or target <= 0) {
            if(target == 0 && n == 0) {
                return 1;
            }

            return 0;
        }

        int res = 0;

        if(dp[n][target] != -1) {
            return dp[n][target];
        }

        for (auto i = 1; i <= k; i++) {
            res = (res + f(n - 1, k, target - i, dp)) % MOD;
        }

        return dp[n][target] = res;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(31, vector<int>(1001, -1));
        return f(n, k, target, dp);
    }
};```



