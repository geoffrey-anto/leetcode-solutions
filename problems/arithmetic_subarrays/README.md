# Arithmetic Subarrays

## Leetcode Link: [Arithmetic Subarrays](https://leetcode.com/problems/arithmetic-subarrays/)
### Language: C++

```cpp
class Solution {
public:
    
    bool checkArithmetic(vector<int> nums){
        sort(nums.begin(),nums.end());
        int diff=nums[1]-nums[0];
        for(int i=0;i<nums.size()-1;i++){
            if(diff!=nums[i+1]-nums[i]){
                return false;
            }
        }
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size();
        int m=l.size();
        vector<bool> ans(m,false);
        for(int i=0;i<m;i++){
            int low=l[i];
            int high=r[i];
            vector<int> temp={};
            for(int j=low;j<=high;j++){
                temp.push_back(nums[j]);
            }
            ans[i]=checkArithmetic(temp);
        }
        return ans;
    }
};```



