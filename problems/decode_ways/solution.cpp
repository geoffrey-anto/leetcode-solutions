class Solution {
public:
    int f(int i, string s, int n, vector<int> &dp) {
        if(i == n) {
            return 1;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int ans = 0;

        if(s[i] != '0') {
            ans += f(i+1, s, n, dp);
        }

        if(i+1 < n && (s[i] == '1' or (s[i] == '2' && s[i+1] < '7'))) {
            ans += f(i+2, s, n, dp);
        }

        return dp[i] = ans;

    }
    int numDecodings(string s) {
        int n = s.length();
        // vector<int> dp(s.length()+1, 0);
        // dp[n] = 1;

        int curr = 0;
        int prev = 1;
        int lastP = 0;

        for(int i=n-1; i>=0; i--) {
            int ans = 0;

            if(s[i] != '0') {
                ans += prev;
            }

            if(i+1 < n && (s[i] == '1' or (s[i] == '2' && s[i+1] < '7'))) {
                ans += lastP;
            }

            curr = ans;

            lastP = prev;
            prev = curr;
        }

        // return f(0, s, s.length(), dp);
        return curr;
    }
};