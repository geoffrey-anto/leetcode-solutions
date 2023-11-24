class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        if(n < m) {
            str1.swap(str2);
            swap(n, m);
        }
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                dp[i][j] = str1[i-1] == str2[j-1] ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int lcs_len = dp[n][m];

        string lcs = "";
        int i = n;
        int j = m;

        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                lcs = str1[i-1] + lcs;
                // cout << "m - " << str1[i-1] << endl;
                i--;
                j--;
            } else if(dp[i-1][j] < dp[i][j-1]) {
                // cout << "j - " << str2[j-1] << endl;
                lcs = str2[j-1] + lcs;
                j--;
            } else {
                // cout << "i - " << str1[i-1] << endl;
                lcs = str1[i-1] + lcs;
                i--;
            }
        }

        // cout << i << endl;
        // cout << j << endl;

        while(j) {
            lcs = str2[--j] + lcs;
        }
    
        while(i) {
            lcs = str1[--i] + lcs;
        }



        return lcs;
    }
};
