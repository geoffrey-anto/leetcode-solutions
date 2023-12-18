# Single Number

## Leetcode Link: [Single Number](https://leetcode.com/problems/single-number/)
### Language: C++

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for(auto &i: nums) {
            num ^= i;
        }
        return num;
    }
};```



