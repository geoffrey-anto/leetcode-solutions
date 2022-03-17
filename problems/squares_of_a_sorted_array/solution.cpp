class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int pos=0;
        int l = nums.size();
        for(int i=0;i<l;i++){
            nums[i]*=nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};