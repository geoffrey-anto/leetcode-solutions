class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int n = nums.size();
        int h = n-1;
        int idx = 0;
        int m = -1;
        while(l<=h) {
            m =  l+ h-l/ 2;

            if(nums[m] == target) {
                break;
            } else if(nums[m] > target) {
                h = m-1;
            } else {
                l = m+1;
            }
        }

        if(m==-1 or nums[m] != target) {
            return {-1, -1};
        }

        int lb=m;
        int ub=m;
        while(lb>0) {
            if(nums[lb-1] == target) {
                lb--;
            } else {
                break;
            }
        }

        while(ub<n-1) {
            if(nums[ub+1] == target) {
                ub++;
            } else {
                break;
            }
        }
        return {lb, ub};
    }
};
