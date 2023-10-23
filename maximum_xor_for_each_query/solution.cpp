class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int c = 0;
        vector<int> ans;
        int k = pow(2,maximumBit) - 1;
        for(int i=0;i<nums.size();i++)
        {
            c = c ^ nums[i];
            ans.push_back(k ^ c);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};