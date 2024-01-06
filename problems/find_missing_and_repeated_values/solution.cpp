class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        for(auto &v: grid) {
            for(auto &i: v) {
                mp[i]++;
            }
        }
        vector<int> ans(2, 0);
        for(auto &[k, v]: mp) {
            if(v == 2) {
                ans[0] = k;
            }
        }
        
        int n = grid.size();
        
        for(int i=1; i<=n*n; i++) {
            if(mp[i] == 0) {
                ans[1] = i;
            }
        }
        
        return ans;
    }
};