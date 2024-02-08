# Divide Array Into Arrays With Max Difference

## Leetcode Link: [Divide Array Into Arrays With Max Difference](https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/)
### Language: C++

```cpp
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        ans.push_back({nums[0]});
        
        for(int i=1; i<n; i++) {
            if(nums[i] - ans.back()[0] <= k and ans.back().size() < 3) {
                ans.back().push_back(nums[i]);
            } else {
                if(ans.back().size() != 3) {
                    return {};
                }
                ans.push_back({nums[i]});
            }
        }
        
        return ans;
    }
};```



