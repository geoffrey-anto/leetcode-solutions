class Solution {
public:
    void solve(vector<int> &nums, int idx, vector<int> &ds, vector<vector<int>> &ans, int n) {
        ans.push_back(ds);

        for(auto i=idx; i<n; i++) {
            if(i > idx && nums[i] == nums[i-1]) {
                continue;
            }

            ds.push_back(nums[i]);
            solve(nums, i+1, ds, ans, n);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(nums, 0, ds, ans, n);
        return ans;
    }
};
