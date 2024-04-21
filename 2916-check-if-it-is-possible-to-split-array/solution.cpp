class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        bool ans = false;

        int  n = nums.size();

        if(nums.size() == 1) {
            return true;
        }

        if(nums.size() == 2) {
            return true;
        }

        for(int i=1; i<n; i++) {
            // int s = 0;
            // for(int j=i; j<n; j++) {
            //     s += nums[j];
            //     if(s >= m and abs(i - j) != n-1) {
            //         return true;
            //     }
            // }

            if(nums[i] + nums[i-1] >= m) {
                ans = true;
            }
        }

        return ans;
    }
};
