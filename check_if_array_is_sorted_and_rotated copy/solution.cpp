class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size() == 1) {
            return true;
        }
        int n = nums.size();
        
        int pt = 1;
        while(pt < n) {
            if(nums[pt-1] <= nums[pt]) {
                pt++;
                continue;
            } else {
                break;
            }
        }

        for(auto i=pt; i<n-1; i++) {
            if(nums[i] > nums[i+1]) {
                return false;
            }
        }

        cout << pt << endl;

        if(pt == n) {
            return true;
        }

        int lower = nums[0];
        int high = nums[n-1];
        int leftMid = nums[pt-1];
        int rightMid = nums[pt];
        if((rightMid <= high) and (high <= lower)) {
            return true;
        }

        return false;
    }
};