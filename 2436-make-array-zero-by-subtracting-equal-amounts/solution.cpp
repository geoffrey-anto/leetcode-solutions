class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0;

        for(i =0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                break;
            }
        }

        if(i == nums.size()) {
            return 0;
        }

        int prev = 0;

        int ans = 0;

        for(; i<nums.size(); i++) {
            if(nums[i] == prev) {
                continue;
            } else {
                ans ++;
            }

            prev = nums[i];
        }

        return ans;
    }
};
