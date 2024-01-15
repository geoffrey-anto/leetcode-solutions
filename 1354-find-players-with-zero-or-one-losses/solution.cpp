class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2, vector<int>());

        unordered_map<int, int> mp;
        unordered_set<int> st;

        for(auto &i: matches) {
            mp[i[1]]++;
            st.insert(i[0]);
            st.insert(i[1]);
        }

        for(auto &[k, v]: mp) {
            if(v == 1) {
                ans[1].push_back(k);
            }
        }

        for(auto &i: st) {
            if(mp[i] == 0) {
                ans[0].push_back(i);
            }
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};
