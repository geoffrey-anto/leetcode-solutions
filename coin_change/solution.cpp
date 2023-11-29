class Solution {
public:
    int MAX = 1e8;
    int f(int i, int a, vector<int> &coins, int n, vector<vector<int>> &dp) {
   
        if(i==n-1) {
            if(a % coins[i] == 0) return a/ coins[i];

            return MAX;
        }

        if(dp[i][a] != -1) return dp[i][a];


            int notTake = f(i+1, a, coins, n, dp);
            int take = MAX;
            if(a >= coins[i]) {
                take = 1+f(i, a - coins[i], coins, n, dp); 
            }

        return dp[i][a] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
       int res = f(0, amount, coins, coins.size(), dp);

        return res >= MAX ? -1 : res;
    }
};