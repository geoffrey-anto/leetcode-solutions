class Solution {
public:
    bool f(vector<int> &nums, int &m, int &k) {
        int ans = 0;

        unordered_map<int, int> mp;
        int l = 0;

        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;

            if(mp[nums[i]] >= m) {
                return true;
            }

            if(i >= k + m - 1) {
                mp[nums[l]]--;
                l++;
            }
        }

        return false;
    }

    int longestEqualSubarray(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size();

        int an = 0;

        while(l <= r) {
            int m = (l + ( r - l ) / 2);

            auto a = f(nums, m, k);

            if(a) {
                an = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return an;
    }
};
