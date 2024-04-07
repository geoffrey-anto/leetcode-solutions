class Solution {
public:
    // MEM
    bool f(int i, int c, string &s, vector<vector<int>> &dp) {
        if(i == s.size()) {
            if(c == 0) {
                return true;
            } else {
                return false;
            }
        }

        if(dp[i][c] != -1) {
            return dp[i][c];
        }

        bool ans = false;

        if(s[i] == '*') {
            ans = ans | f(i+1, c+1, s, dp);
            if(c > 0)
                ans = ans | f(i+1, c-1, s, dp);
            ans = ans | f(i+1, c, s, dp);
        } else if(s[i] == '(') {
            ans = f(i+1, c+1, s, dp);
        } else if(s[i] == ')' and c > 0) {
            ans = f(i+1, c-1, s, dp);
        }
        return dp[i][c] = ans;
    }

    // TAB
    bool checkValidStringTAB(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int> (s.size()+1, 0));

        int n = s.size();

        dp[n][0] = 1;

        for(int i=n-1; i>=0; i--) {
            for(int c=n-1; c>=0; c--) {
                bool ans = false;

                if(s[i] == '*') {
                    ans = ans | dp[i+1][c+1];
                    if(c > 0)
                        ans = ans | dp[i+1][c-1];
                    ans = ans | dp[i+1][c];
                } else if(s[i] == '(') {
                    ans = dp[i+1][c+1];
                } else if(s[i] == ')' and c > 0) {
                    ans = dp[i+1][c-1];
                }

                dp[i][c] = ans;
            }
        }

        return dp[0][0];
        // return f(0, 0, s, dp);
    }

    // SPACE OPTI
    bool checkValidString(string s) {
        vector<int> curr(s.size()+1, 0);
        vector<int> prev(s.size()+1, 0);

        int n = s.size();

        prev[0] = 1;

        for(int i=n-1; i>=0; i--) {
            for(int c=n-1; c>=0; c--) {
                bool ans = false;

                if(s[i] == '*') {
                    ans = ans | prev[c+1];
                    if(c > 0)
                        ans = ans | prev[c-1];
                    ans = ans | prev[c];
                } else if(s[i] == '(') {
                    ans = prev[c+1];
                } else if(s[i] == ')' and c > 0) {
                    ans = prev[c-1];
                }

                curr[c] = ans;
            }
            prev = curr;
        }

        return curr[0];
    }
};
