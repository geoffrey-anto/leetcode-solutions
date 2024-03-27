class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int prev = 0;
        int mx = 0;
        vector<int> pre(nums.size(), 0);
        int currSum = 0;

        int temp = 0;

        for(int i=0; i<nums.size(); i++) {
            temp += nums[i];
            pre[i] = temp;
        }

        unordered_map<int, int> mp;

        int ans = 0;

        int i = 0, j = 0;

        while(j < nums.size()) {
            if(mp[nums[j]]) {
                while(mp[nums[j]]) {
                    mp[nums[i]]--;
                    i++;
                }
            } else {
                ans = max(ans, pre[j] - pre[i] + nums[i]);
                mp[nums[j]]++;
                j++;
            }
        }

        return ans;
    }
};
