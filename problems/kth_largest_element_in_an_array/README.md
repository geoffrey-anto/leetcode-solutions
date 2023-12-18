# Kth Largest Element In An Array

## Leetcode Link: [Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
### Language: C++

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};```



