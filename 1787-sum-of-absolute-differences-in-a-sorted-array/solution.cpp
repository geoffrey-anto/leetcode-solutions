class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(nums.size(), 0), post(nums.size(), 0);

        for(int i=0; i<n; i++) {
            if(i == 0) {
                pre[i] = nums[i];
                continue;
            }

            pre[i] = abs(pre[i-1] + nums[i]);
        }
        
        for(int i=n-1; i>=0; i--) {
            if(i == n-1) {
                post[i] = nums[i];
                continue;
            }

            post[i] = abs(post[i+1] + nums[i]);
        }

        vector<int> ans(n, 0);

        for(int i=0; i<n; i++) {
            int temp=(i+1)*nums[i]-pre[i];
            temp+=(post[i]-((n-i)*nums[i]));
            ans[i] = (temp);
        }

        return ans;
    }
};
