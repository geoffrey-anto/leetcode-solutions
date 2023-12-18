# Shuffle The Array

## Leetcode Link: [Shuffle The Array](https://leetcode.com/problems/shuffle-the-array/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[n+i]);
        }
        return ans;
    }
};```



