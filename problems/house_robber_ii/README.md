# House Robber Ii

## Leetcode Link: [House Robber Ii](https://leetcode.com/problems/house-robber-ii/)
### Language: C++

```cpp
class Solution {
public:
    int solve(vector<int> &nums, int i, vector<int> &dp) {
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        int a = solve(nums, i-1, dp);
        int b = solve(nums, i-2, dp) + nums[i];

        return dp[i] = max(a, b);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);

        vector<int> n1, n2;

        for(int i=0; i<n;i++) {
            if(i!=0) {
                n1.push_back(nums[i]);
            }

            if(i != n-1) {
                n2.push_back(nums[i]);
            }
        }

        return max(solve(n1, n1.size()-1, dp1), solve(n2, n2.size()-1, dp2));
    }
};```



