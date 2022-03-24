class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        int r=n-1;
        int mid=-1;
        while(l<=r){
            mid = l+ r-l / 2;
            if(nums[mid]==target){
                return mid;
            } else if(nums[mid] > target) {
                r = mid-1;
            } else {
               l = mid+1;
            }
        }
        if(target>nums[mid]){
            return mid+1;
        }
        if(mid==0){
            return 0;
        }
        return mid-1;
    }
};
