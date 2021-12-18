class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int c=0,mx=INT_MIN;
        int curr=0,currmax=0;
        for(int i = 0; i<n;i++){
            mx=max(mx,nums[i]);
            curr+=nums[i];
            currmax=max(curr,currmax);
            if(curr<0){
                 curr=0;
                 c++;
        }
    }
        if(c!=n){
            return currmax;
        }
        else{
            return mx;
        }
        return currmax;
    }
};