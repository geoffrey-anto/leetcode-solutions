# Rearrange Array Elements By Sign

## Leetcode Link: [Rearrange Array Elements By Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int neg = 0, pos = 0;
        int idx = 0;
        int n = nums.size();
        vector<int> ans;
        while(neg < n && pos < n) {
            while(nums[neg] > 0) {
                neg++;
            }
            while(nums[pos] < 0) {
                pos++;
            }
            ans.push_back(nums[pos]);
            ans.push_back(nums[neg]);
            pos++;
            neg++;
        }
        return ans;
    }
};```



