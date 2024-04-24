class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long recentMerge = 0ll;
        
        int n = nums.size();

        int i = n - 2;

        vector<long long> cpy;

        for(auto i: nums) {
            cpy.push_back((long long)i);
        }

        while(i >= 0) {
            if(cpy[i+1] >= cpy[i]) {
                cpy[i] = cpy[i] + cpy[i+1];
            }

            recentMerge = max(recentMerge, (long long)cpy[i]);

            i--;
        }

        return max(recentMerge, *max_element(begin(cpy), end(cpy)));
    }
};
