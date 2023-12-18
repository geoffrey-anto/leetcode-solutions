class Solution {
public:
    bool f(vector<int> &nums, int idx, unordered_map<int, bool> &mp) {
        if(mp.find(idx) != mp.end()) {
            return mp[idx];
        }
        bool ans = false;
        if(idx > 0 && (nums[idx] == nums[idx-1])) {
            ans |= f(nums, idx-2, mp);
        }

        if(idx > 1 && (nums[idx] == nums[idx-1]) && (nums[idx-1] == nums[idx-2])) {
            ans |= f(nums, idx-3, mp);
        }
        if(idx > 1 && (nums[idx] == nums[idx-1]+1) && (nums[idx-1] == nums[idx-2]+1)) {
            ans |= f(nums, idx-3, mp);
        }
        return mp[idx] = ans;
    }
    bool validPartition(vector<int>& nums) {
        unordered_map<int, bool> mp = {{-1, true}};
        return f(nums, nums.size()-1, mp);
    }
};