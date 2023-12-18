# Maximum Product Of Two Elements In An Array

## Leetcode Link: [Maximum Product Of Two Elements In An Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/)
### Language: C++

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums[nums.size()-1]-1)*(nums[nums.size()-2]-1);
    }
};```



