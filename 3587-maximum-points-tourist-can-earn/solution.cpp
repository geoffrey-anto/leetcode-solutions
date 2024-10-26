class Solution {
public:
    int f(int i, int j, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore, int n, int kk, vector<vector<int>> &dp) {
        if(j >= kk) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int stay = stayScore[j][i] + f(i, j + 1, stayScore, travelScore, n, kk, dp);
        
        int move = 0;


        for(int k=0; k<n; k++) {
            if(k != i)
                move = max(move, travelScore[i][k] + f(k, j + 1, stayScore, travelScore, n, kk, dp));
        }
        
        return dp[i][j] = max(stay, move);
    }

    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int ans = 0;

        vector<vector<int>> dp(n+1, vector<int>(k + 1, -1));

        for(int i=0; i<n; i++) {
            ans = max(ans, f(i, 0, stayScore, travelScore, n, k, dp));
        }

        return ans;
    }
};
