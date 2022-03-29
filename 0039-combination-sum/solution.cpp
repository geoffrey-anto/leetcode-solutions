class Solution {
public:
    
    void f(int idx, vector<int> &c, int target, vector<int> &stk, vector<vector<int>> &ans){
        if(idx == c.size()){
            if(target==0){
                ans.push_back(stk);
            }
            return;
        }
        
        if(target>=c[idx]){
            stk.push_back(c[idx]);
            f(idx, c, target-c[idx], stk, ans);
            stk.pop_back();
        }
        f(idx+1, c, target, stk, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> stk;
        f(0,candidates,target,stk,ans);
        return ans;
    }
};
