class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int can = nums[0];
        int n = nums.size();

        for(int i=1; i<n; i++) {
            if(can != nums[i]) {
                cnt--;
            } else {
                cnt++;
            }

            if(cnt < 0) {
                can = nums[i];
                cnt = 1;
            }
        }

        return can;
    }
};
