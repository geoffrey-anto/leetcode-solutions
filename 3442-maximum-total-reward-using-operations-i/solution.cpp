class Solution {
public:
    int dp[2001][2001*2];
    int f(int i, int currMax, vector<int>& arr) {
        if(i == arr.size()) {
            return 0;
        }

        if(dp[i][currMax] != -1) {
            return dp[i][currMax];
        }

        int t = -1;

        if(arr[i] > currMax) {
            t = arr[i] + f(i+1, currMax + arr[i], arr);
        }

        int nt = f(i+1, currMax, arr);
        
        return dp[i][currMax] = max(nt, t);
    }

    int maxTotalReward(vector<int>& rewardValues) {
        memset(dp, -1, sizeof(dp));
        sort(begin(rewardValues), end(rewardValues));
        return f(0, 0, rewardValues);
    }
};
