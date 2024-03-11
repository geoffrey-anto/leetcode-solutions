using ll = long long;
#define MIN (-1e15 - 1)

class Solution {
public:
    long long f(int i, int j, bool s, vector<int>& nums, int n, int k, vector<vector<vector<ll>>> &dp) {
        // i -> index
        // k -> kth subarray
        // if we are curr taking a subarray -> s

        if(i == n) {
            if(j == 1) {
                if(s == true) {
                    return 0;
                }
            }

            return MIN;
        }

        if(j == 0) {
            return 0;
        }

        if(dp[i][j][s] != MIN) {
            return dp[i][j][s];
        }

        long long p = (ll)nums[i] * (ll)j * (j % 2 == 0 ? -1 : 1) + f(i+1, j, true, nums, n, k, dp);

        long long e = p;

        if(s) { // means we can do a end simulation
            e = max(e, f(i, j-1, false, nums, n, k, dp));
        }

        ll np = MIN;

        if(!s) {
            np = f(i+1, j, false, nums, n, k, dp);
        }

        return dp[i][j][s] = max(e, np);

    }
    long long maximumStrength(vector<int>& nums, int k) {
        vector<vector<vector<ll>>> dp(nums.size(), vector<vector<ll>>(k+1, vector<ll>(2, MIN))); 
        return f(0, k, false ,nums, nums.size(), k, dp);
    }
};
