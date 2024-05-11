class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans(nums.size(), 0ll);

        int currMax = nums[0];

        ans[0] = (long long)nums[0] * 2ll;

        for(int i=1; i<nums.size(); i++) {
            currMax = max(nums[i], currMax);

            ans[i] = (ans[i-1]) + ((long long)nums[i] + (long long)currMax); 
        }

        return ans;
    }
};
