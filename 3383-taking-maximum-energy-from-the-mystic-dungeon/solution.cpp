class Solution {
public:
    int f(int i, int k, vector<int>& e, int n, vector<int> &dp) {
        if(i >= n) {
            return 0;
        }

        if(dp[i+1] != -1) {
            return dp[i+1];
        }

        int ans = INT_MIN;

        if(i == -1) {
            for(int j=0; j<n; j++) {
                int a = f(j, k, e, n, dp);
                ans = max(ans, a);
            }
        } else {
            ans = e[i] + f(i+k, k, e, n, dp);
        }

        return dp[i+1] = ans;
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n+2, -1);
        return f(-1, k, energy, n, dp);
    }
};
