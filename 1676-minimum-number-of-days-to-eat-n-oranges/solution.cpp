class Solution {
public:
    int f(int n, unordered_map<int, int>& dp) {
        if(n == 0) {
            return 0;
        }

        if(n == 1) {
            return 1;
        }

        if(dp.find(n) != dp.end()) {
            return dp[n];
        }

        int half = (n%2) + f(n/2, dp);
        int twoThirds = (n%3) + f(n/3, dp);

        return dp[n] = 1 + min(half, twoThirds);
    }
    int minDays(int n) {
        unordered_map<int, int> dp;
        return f(n, dp);
    }
};
