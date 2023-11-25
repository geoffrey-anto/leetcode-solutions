class Solution {
public:
    int f(int i, int j, string word1, string word2, vector<vector<int>> &dp) {
        if(i < 0) return j+1;
        if(j < 0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) {
            return f(i-1, j-1, word1, word2, dp);
        }

        int rem = f(i-1, j, word1, word2, dp);
        int ins = f(i, j-1, word1, word2, dp);
        int rep = f(i-1, j-1, word1, word2, dp);

        return dp[i][j] = 1 + min(rem, min(ins, rep));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n-1, m-1, word1, word2, dp);
    }
};
