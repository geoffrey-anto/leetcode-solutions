# Minimum Cost To Cut A Stick

## Leetcode Link: [Minimum Cost To Cut A Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)
### Language: C++

```cpp
class Solution {
public:
    int f(int l, int r, int i, int j, vector<int>& cuts, vector<vector<int>> &dp) {
        if(i == j) {
            return r - l;
        }

        if(i > j) {
            return 0;
        }

        if(l >= r) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int mn = 1e9;


        for(int cut=i; cut<=j; cut++) {
            int res = (r - l) + f(l, cuts[cut], i, cut-1, cuts, dp) + f(cuts[cut], r, cut+1, j, cuts, dp);
            if(res < mn) {
                mn = res;
            } 
        }

        return dp[i][j] = mn;
    }
    int minCost(int n, vector<int>& cuts) {
        int N = cuts.size();
        vector<vector<int>> dp(101, vector<int>(101, -1));
        sort(cuts.begin(), cuts.end());
        return f(0,n,0, N-1, cuts, dp);
    }
};```



