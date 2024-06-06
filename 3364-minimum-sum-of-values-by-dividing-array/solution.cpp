class Solution {
public:
    long long ONES = 0xFFFFFFFFF;
    long long f(int i, int j, long long curr, vector<int>& nums, vector<int>& andValues, vector<vector<unordered_map<long long, long long>>> &dp) {
        if(j == andValues.size()) {
            if(i == nums.size()) {
                return 0;
            }

            return ONES;
        } else {
            if(i == nums.size()) {
                return ONES;
            }
        }

        if(dp[i][j].count(curr) != 0) {
            return dp[i][j][curr];
        }

		long long nt = f(i+1, j, curr & nums[i], nums, andValues, dp);

        long long t = ONES;

        if((curr & nums[i]) == andValues[j]){
			t = nums[i] + f(i+1, j+1, ONES, nums, andValues, dp);
		}

        return dp[i][j][curr] = min(nt, t);
    }

    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        vector<vector<unordered_map<long long, long long>>> dp(nums.size()+1, vector<unordered_map<long long, long long>>(andValues.size(), unordered_map<long long, long long>()));

        long long ans = f(0, 0, ONES, nums, andValues, dp);

        if(ans == ONES) {
            return -1;
        } else {
            return ans;
        }
    }
};
