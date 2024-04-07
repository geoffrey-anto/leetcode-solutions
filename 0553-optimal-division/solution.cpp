class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans = "";

        if(nums.size() == 1) {
            return to_string(nums[0]);
        }

        if(nums.size() == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }

        ans += to_string(nums[0]);
        ans += "/(";

        for(int i=1; i<nums.size()-1; i++) {
            ans += to_string(nums[i]) + '/';
        }
        ans += to_string(nums[nums.size()-1]);
        ans += ')';

        return ans;
    }
};
