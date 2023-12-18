# Subsets Ii

## Leetcode Link: [Subsets Ii](https://leetcode.com/problems/subsets-ii/)
### Language: C++

```cpp
class Solution {
public:
    void f(vector<vector<int>> &ans, vector<int> temp, int idx, vector<int> nums){
            ans.push_back(temp);

        for(int i=idx; i<nums.size(); i++) {
            if(idx!=i && nums[i-1]==nums[i]) continue;

            temp.push_back(nums[i]);
            f(ans, temp, i+1, nums);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        f(ans, temp, 0, nums);
        return ans;
    }
};```



