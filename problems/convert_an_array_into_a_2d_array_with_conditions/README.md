# Convert An Array Into A 2D Array With Conditions

## Leetcode Link: [Convert An Array Into A 2D Array With Conditions](https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/)
### Language: C++

```cpp
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        vector<int> map(maxEle + 1, 0);

        int mx = 0;

        for(auto &i: nums) {
            map[i]++;
            mx = max(mx, map[i]);
        }

        vector<vector<int>> ans(mx, vector<int>());
        int n = nums.size();

        for(int i=0; i<=maxEle; i++) {
            int val = map[i];

            if(val == 0) {
                continue;
            }

            for(int j=0; j<val; j++) {
                ans[j].push_back(i);
            }
        }

        return ans;
    }
};```



