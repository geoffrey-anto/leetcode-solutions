# Squares Of A Sorted Array

## Leetcode Link: [Squares Of A Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int pos=0;
        int l = nums.size();
        for(int i=0;i<l;i++){
            nums[i]*=nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};```



