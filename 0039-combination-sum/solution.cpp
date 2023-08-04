class Solution {
public:
    template <typename T>
    void print(T arr)
    {
        for (auto i : arr)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    void f(vector<int> &arr, int idx, int sum, int n, vector<int> &ds, vector<vector<int>> &ans){
        if(idx == arr.size()) {
            if(sum == 0) {
                ans.push_back(ds);
            }
            return ;
        }

        // PICK
        if(arr[idx] <=sum) {
            ds.push_back(arr[idx]);
            f(arr, idx, sum - arr[idx], n, ds, ans);
            ds.pop_back();
        }

        // NOT PICK
        f(arr, idx+1, sum, n, ds, ans);

        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        f(candidates, 0, target, candidates.size(), ds, ans);
        return ans;
    }
};
