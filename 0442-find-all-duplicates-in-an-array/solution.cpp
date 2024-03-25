class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        bitset<100000> mp;
        vector<int> ans;

        for(auto i: nums) {
            if(mp.test(i)) {
                ans.push_back(i);
            } else {
                mp.set(i);
            }
        }

        return ans;
    }
};
