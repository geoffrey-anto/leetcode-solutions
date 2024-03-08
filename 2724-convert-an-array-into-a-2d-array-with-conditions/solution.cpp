class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> mp;
        
        for(auto i: nums) {
            mp[i]++;
        }
        
        priority_queue<pair<int, int>> pq;
        
        for(auto &[k, v]: mp) {
            pq.push({v, k});
        }
        
        vector<vector<int>> ans(pq.top().first, vector<int>());
        
        while(!pq.empty()) {
            pair<int, int> t = pq.top();
            for(int i=0; i<t.first; i++) {
                ans[i].push_back(t.second);
            }
            pq.pop();
        }
        
        return ans;
    }
};
