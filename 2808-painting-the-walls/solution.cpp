class Solution {
public:
    int dp[1000][1000];

    int f(vector<int> &cost, vector<int> &time, int ind, int taskRemaining){
        if(taskRemaining <= 0) {
            return 0;
        }

        if(ind == time.size()) {
            return 1e9;
        }

        if(dp[ind][taskRemaining] != -1) {
            return dp[ind][taskRemaining];
        }

        int take = cost[ind] + f(cost, time, ind+1, taskRemaining - time[ind] -1);

        int notTake = f(cost, time, ind+1, taskRemaining);

        return dp[ind][taskRemaining] = min(take, notTake);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof(dp));

        return f(cost, time, 0, cost.size());
    }
};
