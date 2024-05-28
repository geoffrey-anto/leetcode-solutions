class Solution {
public:
    int dp[202][102][102][3];
    int f(int i, string s3, int j, string s1, int k, string s2, bool turn) {
        if(i >= s3.size() and j >= s1.size() and k >= s2.size()) {
            return true;
        }

        if(i >= s3.size()) {
            return false;
        }

        if(j >= s1.size() and turn == true) {
            return false;
        }

        if(k >= s2.size() and turn == false) {
            return false;
        }

        if(dp[i][j][k][turn] != -1) {
            return dp[i][j][k][turn];
        }

        bool ans = false;

        if(turn) {
            for(int x=i; x<s3.size(); x++) {
                int sz = x - i + 1;
                if(j + sz > s1.size()) {
                    break;
                }

                if(s1.substr(j, sz) == s3.substr(i, sz)) {
                    ans = ans | f(x+1, s3, j+sz, s1, k, s2, 0);
                } else {
                    break;
                }
            }
        } else {
            for(int x=i; x<s3.size(); x++) {
                int sz = x - i + 1;
                if(k + sz > s2.size()) {
                    break;
                }

                if(s2.substr(k, sz) == s3.substr(i, sz)) {
                    ans = ans | f(x+1, s3, j, s1, k+sz, s2, 1);
                } else {
                    break;
                }
            }
        }

        return dp[i][j][k][turn] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int l = s3.size();
        if (n + m != l) {
            return false;
        }


        memset(dp, -1, sizeof(dp));

        return f(0, s3, 0, s1, 0, s2, 0) or f(0, s3, 0, s1, 0, s2, 1);
    }
};
