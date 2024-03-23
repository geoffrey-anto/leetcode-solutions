class Solution {
public:
    vector<vector<int>> ans;
    void f(int i, int s, vector<int>& can, int t, vector<int> ds) {
        if(s > t) {
            return;
        }


        if(i == can.size()) {
            if(s == t) {
                ans.push_back(ds);
            }

            return;
        }

        ds.push_back(can[i]);
        f(i, s+can[i], can, t, ds);
        ds.pop_back();

        f(i+1, s, can, t, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        f(0, 0, can, t, {});

        return ans;
    }
};
