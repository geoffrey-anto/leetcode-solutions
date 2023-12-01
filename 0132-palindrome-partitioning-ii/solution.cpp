class Solution {
public:
    bool isPalin(int l, int r, string &s) {
        while(l<=r) {
            if(s[l] != s[r]) return false;

            l++;
            r--;
        } 
        return true;
    } 

    int f(int i, int n, string &s) {
        if(i == n) {
            return 0;
        }

        int mn = 1e8;

        for(int j=i; j<n; j++) {

            if(isPalin(i, j, s)) {
                int x = 1 + f(j+1, n, s);
                mn = min(mn, x);
            }

        }

        return mn;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        for(int i=n-1; i>=0; i--) {
            int mn = 1e8;

            for(int j=i; j<n; j++) {

                if(isPalin(i, j, s)) {
                    mn = min(mn, 1 + dp[j+1]);
                }

            }

            dp[i] = mn;
        }

        return dp[0] - 1;
    }
};
