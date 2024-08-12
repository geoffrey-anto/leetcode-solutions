class Solution {
public:
    int atmost(int k, vector<int> &nums) {
        int numsSize = nums.size();
        int i, j=0, count=0, odds=0;
        for (i = 0; i < numsSize; ++i) {
            odds += (nums[i] & 1);
            while(odds == k) {
                count += numsSize - i;
                odds -= (nums[j++] & 1);
            }
        }
        return count;
    }



    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(k, nums) - atmost(k+1, nums);      
    }
};
