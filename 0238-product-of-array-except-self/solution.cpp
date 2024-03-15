class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 1);

        int p=1,s=1;

        for(int i=0;i<n;i++){
            ans[i]*=p;
            ans[n-i-1]*=s;
            p*=nums[i];
            s*=nums[n-i-1];
        }

        return ans;
    }
};
