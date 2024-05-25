class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& q, int x) {
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == x)
                mp[x].push_back(i);
        }

        vector<int> ans;

        for(auto i: q) {
            if(mp[x].size() < i) {
                ans.push_back(-1);
            } else {
                ans.push_back(mp[x][i-1]);
            }
        }

        return ans;
    }
};
