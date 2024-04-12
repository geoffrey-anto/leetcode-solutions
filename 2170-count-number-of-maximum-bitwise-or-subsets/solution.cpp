class Solution {
public:

    int countMaxOrSubsets(vector<int>& nums) {
        int x = nums[0];
        for(int i=1; i<nums.size(); i++) {
            x = x | nums[i];
        }

        long long ans = 0ll;

        for(int i=0; i<pow(2, nums.size()); i++) {
            int curr = 0;
            for(int j=0; j<nums.size(); j++) {
                if((i & (1 << j)) != 0) {
                    curr = curr | nums[j];
                }
            }
            
            if(x == curr) ans++;
        }

        return ans;
    }
};
