class Solution {
public:
    
   void f(int idx, vector<int> &c, int target, vector<int> &stk, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(stk);
            return;
        }
        for(int i=idx; i<c.size(); i++){
            if(i>idx and c[i]==c[i-1]){
                continue;
            }
            if(target<c[i]){
                break;
            }
            stk.push_back(c[i]);
            f(i+1, c, target-c[i], stk, ans);
            stk.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> stk;
        vector<vector<int>> ans;
        f(0, candidates, target, stk, ans);
        return ans;
    }
};
