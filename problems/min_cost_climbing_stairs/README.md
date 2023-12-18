# Min Cost Climbing Stairs

## Leetcode Link: [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)
### Language: C++

```cpp
class Solution {
public:

    int f(vector<int>& cost, int i, int n, vector<int> dp) {
        if ( i >= n-1) {
            return 0;
        }

        if (dp[i] != INT_MAX) return dp[i];

        return dp[i] = min(f(cost, i+1, n, dp) + cost[i], f(cost, i+2, n, dp) + cost[i+1]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(3, 0);
        for(int i=n-2; i>=0; i--){
            dp[i%3]=min(cost[i]+dp[(i+1)%3], cost[i+1]+dp[(i+2)%3]);
        }
        return dp[0];

    }
};```



