class Solution {
public:
    int lcs(string &word1, string &word2) {

        int n = word1.size();
        int m = word2.size();

        string res = word1 + word2;
        
        int x = n + m;

        int ans = 0;

        vector<vector<int>> dp(x, vector<int>(x, 0));

        for(int i=0; i<x; i++) {
            dp[i][i] = 1;
            for(int j=i-1; j>=0; j--) {
                if(res[j] == res[i]) {
                    dp[j][i] = max(dp[j][i], dp[j+1][i-1]+2);

                    // Taking from 2 strings
                    if(j<n && i>=n)
                    {
                        ans=max(ans,dp[j][i]);
                    }

                } else {
                    dp[j][i] = max(dp[j+1][i], dp[j][i-1]);
                }
            }
        }

        return ans;
    }

    int longestPalindrome(string word1, string word2) {
        int len = lcs(word1, word2);

        return len;
    }
};
