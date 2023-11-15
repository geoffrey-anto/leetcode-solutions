class Solution {
public:
    void solve(vector<int> &arr, int idx, int n, vector<vector<int>> &ans, vector<int> &ds, int sum, int target) {
        if(idx == n) {
            if(sum == target) {
                ans.push_back(ds);
            }
            return;
        }

        if(arr[idx] + sum <= target) {
            ds.push_back(arr[idx]);
            solve(arr, idx, n, ans, ds, sum+arr[idx], target);
            ds.pop_back();
        }

        solve(arr, idx+1, n, ans, ds, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       int n = nums.size();
       vector<vector<int>> ans;
       vector<int> ds;

       solve(nums, 0, n, ans, ds, 0, target);

       return ans;
    }
};
