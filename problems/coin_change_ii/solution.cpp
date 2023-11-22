class Solution {
public:
    int f(int i, int a, vector<int> &coins, int n, vector<vector<int>> &dp) {
        if(i==n-1) {
            if(a % coins[i] == 0) return 1;

            return 0;
        }

        if(dp[i][a] != -1) return dp[i][a];


            int notTake = f(i+1, a, coins, n, dp);
            int take = 0;
            if(a >= coins[i]) {
                take = f(i, a - coins[i], coins, n, dp); 
            }

        return dp[i][a] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
       int res = f(0, amount, coins, coins.size(), dp);

        return res;
    }
};