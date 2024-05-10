class Solution {
public:
    int f(int i, vector<vector<int>>& offers, int n, vector<int> &starts, vector<int> &dp) {
        if(i == n) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int notTake = 0 + f(i+1, offers, n, starts, dp);

        auto next = lower_bound(begin(starts)+i+1, end(starts), offers[i][1]+1);

        int take = offers[i][2] + f((int)(next-starts.begin()), offers, n, starts, dp);

        return dp[i] = max(take, notTake);
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(begin(offers), end(offers));

        vector<int> starts;

        for(auto &i: offers) {
            starts.push_back(i[0]);
        }

        vector<int> dp(offers.size()+1, -1);

        return f(0, offers, offers.size(), starts, dp);
    }
};
