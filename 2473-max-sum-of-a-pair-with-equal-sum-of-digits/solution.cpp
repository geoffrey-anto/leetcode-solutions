class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, int> mp;
        int ans = -1;

        for(auto i: nums) {
            int n = 0;
            int cpy = i;
            while(i > 0) {
                n = n + (i % 10);
                i = i / 10;
            }

            if(mp[n] != 0) {
                ans = max(ans, cpy + mp[n]);
            }

            mp[n] = max(mp[n], cpy);
        }


        return ans;
    }
};
