class Solution {
public:
    bool check(vector<int>& nums) {
        int k=0;
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<=nums[i+1] )
            {
                k++;
            }         
        }
        if(k==n-2 && nums[0]>=nums[n-1])
        {
            return true;
        }
        else if(k==n-1)
        {
            return true;
        }
        else
            return false;
    }
};