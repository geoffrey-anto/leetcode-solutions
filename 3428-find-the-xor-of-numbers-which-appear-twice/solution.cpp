class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums) {
            mp[i]++;
        }

        int x = 0;

        for(auto &[k,v]: mp) {
            if(v == 2) {
                x = x ^ k;
            }
        }

        return x;
    }
};
