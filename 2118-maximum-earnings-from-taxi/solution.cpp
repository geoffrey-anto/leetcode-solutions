class Solution {
public:
    vector<int> starts;
    long long f(int i, vector<vector<int>>& rides, vector<long long> &dp) {
        if(i == rides.size()) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        auto nt = f(i+1, rides, dp);

        int j = (lower_bound(begin(starts), end(starts), rides[i][1]) - begin(starts));

        long long t = (long long)rides[i][1] 
                        - (long long)rides[i][0] 
                        + (long long)rides[i][2] 
                        + f(j, rides, dp);

        return dp[i] = max(nt, t);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(begin(rides), end(rides));

        for(auto &i: rides){
            starts.push_back(i[0]);
        }

        vector<long long> dp(rides.size() + 2, 0);
        int m = rides.size();

        for(int i=m-1; i>=0; i--) {
            auto nt = dp[i+1];

            int j = (lower_bound(begin(starts), end(starts), rides[i][1]) - begin(starts));

            long long t = (long long)rides[i][1] 
                            - (long long)rides[i][0] 
                            + (long long)rides[i][2] 
                            + dp[j];

            dp[i] = max(nt, t);
        }

        return dp[0];
    }
};
