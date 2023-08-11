class Solution {
public:
    int f(int idx, int amt, vector<int> &coins, int dp[500][6000]) {
        if(amt == 0) {
            return 1;
        }
        if(dp[idx][amt] != -1) {
            return dp[idx][amt];
        }
        if(idx == coins.size()) {
            return 0;
        }

        int take = 0;
        if(amt >= coins[idx]) {
            take = f(idx, amt-coins[idx], coins, dp);
        }
        int notTake = 0;
        notTake = f(idx+1, amt, coins, dp);

        return dp[idx][amt] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int dp[500][6000];
        memset(&dp, -1, sizeof(dp));
        return f(0, amount, coins, dp);
    }
};