class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) {
            return 0;
        }

        int n = nums.size();

        sort(begin(nums), end(nums));

        int ans = nums[n-1] - nums[0];

        for(int i=0; i<=3; i++) {
            ans = min(ans, nums[n - 3 + i - 1] - nums[i]);
        }

        return ans;
    }
};
