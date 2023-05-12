class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &i:nums) {
            if(m.find(i)!=m.end()) {
                return true;
            } else {
                m.insert({i,1});
            }
        }
        return false;
    }
};
