# Combination Sum Iii

## Leetcode Link: [Combination Sum Iii](https://leetcode.com/problems/combination-sum-iii/)
### Language: C++

```cpp
class Solution {
public:
    void solve(vector<int> &nums, int idx, int sum, int k, int n, vector<vector<int>> &ans, vector<int> &ds) {
        if(ds.size() == k) {
            if(n == sum) {
                ans.push_back(ds);
            }
            return;
        }
        cout << ds.size() << endl;
        if(idx >= 9) return;
        
        if(nums[idx]+sum > n) return;
        
        ds.push_back(nums[idx]);
        solve(nums, idx+1, sum + nums[idx],k, n, ans, ds);
        ds.pop_back();

        solve(nums, idx+1,sum, k, n, ans, ds);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        solve(nums, 0, 0,k, n, ans, ds);
        return ans;
    }
};```



