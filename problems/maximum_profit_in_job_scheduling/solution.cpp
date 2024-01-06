class Solution {
public:
    int lower_bound(int &k, vector<vector<int>> &arr, int &n) {
        int l = 0, h = n - 1, t = n + 1;
        while(l <= h){
            int m = (l + h) >> 1;
            if(arr[m][0] >= arr[k][1]) t = m, h = m - 1;
            else l = m + 1;
        }
        return t;
    }

    int f(int i, vector<vector<int>> &arr, int &n, vector<int> &dp) {
        if(i >= n) {
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int notTake = f(i+1, arr, n, dp);

        int j = lower_bound(i, arr, n);

        int take = arr[i][2] + f(j, arr, n, dp);

        return dp[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = size(profit);

        vector<vector<int>> arr;

        for(int i=0; i<n; i++) {
            arr.push_back({startTime[i], endTime[i], profit[i]});
        }

        vector<int> dp(n, -1);

        sort(arr.begin(), arr.end());

        return f(0, arr, n, dp);
    }
};