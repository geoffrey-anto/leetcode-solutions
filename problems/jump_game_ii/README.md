# Jump Game Ii

## Leetcode Link: [Jump Game Ii](https://leetcode.com/problems/jump-game-ii/)
### Language: C++

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int c=0;
        while(r<n-1 and l<=r){
            int Mx=0;
            for(int i=l;i<=r;i++){
                Mx=max(Mx,i+nums[i]);
            }
            l=r+1;
            r=Mx;
            c++;
        }
        return c;
    }
};```



