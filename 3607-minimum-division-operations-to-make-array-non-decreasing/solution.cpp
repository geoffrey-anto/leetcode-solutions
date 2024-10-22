class Solution {
public:
    Solution() {
        // fillPrimes();
    }


    int minOperations(vector<int>& nums) {
        int count = 0;

        int n = nums.size();

        if(n == 1) {
            return 0; 
        }

        for(int i = n-2; i>=0; i--) {
            if(nums[i] > nums[i+1]) {
                for(int j=2; j*j <= nums[i]; j++) {
                    if(nums[i]%j == 0) {
                        nums[i] = j;
                        count++;
                        break;
                    }
                }

                if(nums[i] > nums[i+1]) return -1;
            }
        }

        return count;
    }
};
