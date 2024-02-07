class Solution { 
private: 
    string LCS(string a, string b, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int res = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    res = max(res, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        cout << res << endl;

        return "";
    }

    string LCSubStr(string X, string Y){

        int m = X.length();
        int n = Y.length();
    
        int result = 0;
    
        int end;
    
        int len[2][n + 1];
    
        int currRow = 0;
    
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    len[currRow][j] = 0;
                }
                else if (X[i - 1] == Y[j - 1]) {
                    len[currRow][j] = len[1 - currRow][j - 1] + 1;
                    if (len[currRow][j] > result) {
                        result = len[currRow][j];
                        end = i - 1;
                    }
                }
                else {
                    len[currRow][j] = 0;
                }
            }
    
            currRow = 1 - currRow;
        }
    
        if (result == 0) {
            return "";
        }
    
        return X.substr(end - result + 1, result);
    }

    string manacherAlgo(string a) {
        int n = a.size();

        string c((2*n)+1, ' ');
        int i=0;
        c[i++] = '#';

        for(auto ch: a) {
            c[i++] = ch;
            c[i++] = '#';
        }

        int ri = 0;
        int ci = 0;

        int mxS = 0;
        int mxI = 0;

        vector<int> p((2*n)+1, 0);

        for(i=0; i<c.size(); i++) {
            int m = 2*ci - i;

            if(ri > i) {
                p[i] = min(p[m], ri-i);
            }

            int x = i + (p[i]+1);
            int y = i - (p[i]+1);

            while(y >= 0 && x < c.size() && c[x] == c[y]) {
                y--;
                x++;
                p[i]++;
            }

            if(p[i] >= mxS) {
                mxS = p[i];
                mxI = i;
            }

            if(i + p[i] > ri) {
                ci = i;
                ri = i + p[i];
            }
        }

        c = c.substr(mxI-mxS, mxS*2);

        cout << c << endl;
        string res = "";

        for(auto x: c) {
            if(x != '#') {
                res += x;
            }
        }

        return res;
    }
public:
    string longestPalindrome(string s) {
        return manacherAlgo(s);
    }
};
