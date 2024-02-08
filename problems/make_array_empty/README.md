# Make Array Empty

## Leetcode Link: [Make Array Empty](https://leetcode.com/problems/make-array-empty/)
### Language: C++

```cpp
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = 0;
        n = nums.size();

        unordered_map<int, int> map;
        int j = 0;
        for(auto i: nums) {
            map[i] = j;
            j++;
        }

        sort(begin(nums), end(nums));

        long long ans = 1;

        for(int i=n-2; i>=0; i--) {
            if(map[nums[i]]  > map[nums[i+1]]) {
                ans+=(n-i);
            } else {
                ans++;
            }
        }

        return ans;
    }
};```



