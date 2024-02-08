# Minimum Number Of Operations To Make Array Empty

## Leetcode Link: [Minimum Number Of Operations To Make Array Empty](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/)
### Language: C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto i: nums) {
            mp[i]++;
        }

        int ans = 0;

        for(auto &i: mp) {
            if(i.second == 1) return -1;
            ans += i.second / 3;
            if(i.second % 3 != 0) {
                ans++;
            }
        }

        return ans;
    }
};```



