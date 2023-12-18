class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        // so it has a maximum of 31 bits 
        for(int i=0; i<=31; i++) {
            int cnt = 0;
            // count no of nums having set bit
            for(auto &num: nums) {
                if ((num & (1 << i)) != 0) {
                    cnt++;
                }
            }
            
            if(cnt >= k) {
                ans += pow(2,i);
            }
        }

        return ans;
    }
};