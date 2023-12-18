# Jump Game

## Leetcode Link: [Jump Game](https://leetcode.com/problems/jump-game/)
### Language: C++

```cpp
class Solution {
public:
    // int dp[10000];
//     bool helper(vector<int> nums,int n){
//         if(n==0){
//             return true;
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         dp[n]=max(helper(nums,n),helper(nums,nums[n]));
//         return false;
//     }
    
    bool canJump(vector<int>& nums){
        int l=0,r=0;
        int n=nums.size();
        while(r<n-1 and l<=r){
            int Mx=0;
            for(int i=l;i<=r;i++){
                Mx=max(Mx,i+nums[i]);
            }
            l=r+1;
            r=Mx;
        }
        if(r<n-1){
            return false;
        }
        return true;
    }
};```



