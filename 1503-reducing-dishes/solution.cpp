class Solution {
public:
    int f(int i, int t, vector<int>& nums) {
        if(i == nums.size()) {
            return 0;
        }

        int take = (nums[i] * t) + (f(i+1, t+1, nums));
        int notTake = f(i+1, t, nums);

        return max(take, notTake);
    }

    int maxSatisfaction(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> curr(n+2, 0);
        vector<int> prev(n+2, 0);

        for(int i=n-1; i>=0; i--) {
            for(int t=n; t>=1; t--) {
                int take = (nums[i] * t) + prev[t+1];
                int notTake = prev[t];

                curr[t] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[1];
    }
};
