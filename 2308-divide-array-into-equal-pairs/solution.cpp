class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums) {
            mp[i]++;
        }

        for(auto &[k, v]: mp) {
            if(v % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
};
