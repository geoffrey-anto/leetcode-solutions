class Solution {
public:
    void f(vector<int> &nums, int idx, int sum, int n, vector<vector<int>> &ans, vector<int> &ds, int target) {
        if(sum == target) {
            ans.push_back(ds);
        }

        for(int i=idx; i<n; i++) {
            if(i > idx && nums[i] == nums[i-1]) {
                continue;
            }

            if(nums[i] + sum > target) {
                break;
            }

            ds.push_back(nums[i]);
            f(nums, i+1, sum + nums[i], n, ans, ds, target);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        f(nums, 0, 0, n, ans, temp, target);
        return ans;
    }
};