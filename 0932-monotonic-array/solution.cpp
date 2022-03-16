class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool d=true;
        bool x=true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                x=false;
                break;
            } else{
                x=true;
            }
        }
    
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                d=false;
                break;
            } else{
                d=true;
            }
        }
        return x or d;
    }
};
