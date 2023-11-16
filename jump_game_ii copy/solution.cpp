class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int x=0;
        while(r<n-1 and l<=r){
            int mx=0;
            for(int i=l;i<=r;i++){
                mx=max(mx,i+nums[i]);
            }
            x++;
            l=r+1;
            r=mx;
        }
        return x;
    }
};