class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int cnt = 0, r = -1;

        for(int i=0; i<nums.size(); i++)  {
            r = r & nums[i];

            if(r == 0) {
                cnt++;
                r=-1;
            }
        }  

        return cnt ? cnt : 1;
    }
};
