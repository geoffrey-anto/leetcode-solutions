class Solution {
public:
    void func(vector<int> &arr, int idx, int sum, int n, vector<int> &ds, vector<vector<int>> &ans)
{
    if (sum == 0)
    {
        ans.push_back(ds);
    }

    for (int i = idx; i < n; i++)
    {
        if (i > idx && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > sum)
            break;

        ds.push_back(arr[i]);
        func(arr, i + 1, sum - arr[i], n, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> ds;
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    func(candidates, 0, target, candidates.size(), ds, ans);
    return ans;
}
};