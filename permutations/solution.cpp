class Solution {
public:
    void f(vector<int> &n, int idx, vector<vector<int>> &ans){
        if(idx == n.size()) {
            ans.push_back(n);
            return;
        }

        for(int i=idx; i<n.size(); i++) {
            swap(n[i], n[idx]);
            f(n, idx+1, ans);
            swap(n[i], n[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        f(nums ,0 ,ans);
        return ans;
    }
};