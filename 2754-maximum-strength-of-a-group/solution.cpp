class Solution {
public:
    long long ans = INT_MIN;
    void f(int i, vector<int> &nums, long long val, int picks=0) {
        if(i == nums.size()) {
            if(picks != 0)
                ans = max(ans, val);
            return;
        }

        f(i+1, nums, val, picks);

        f(i+1, nums, val * nums[i], picks+1);
    }
    long long maxStrength(vector<int>& nums) {
        f(0, nums, 1ll);

        return ans;
    }
};
