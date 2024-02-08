# Check If Bitwise Or Has Trailing Zeros

## Leetcode Link: [Check If Bitwise Or Has Trailing Zeros](https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/)
### Language: C++

```cpp
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int c1 = 0;
        
        for(auto i: nums) {
            if(i%2 == 0) {
                c1++;
            }
            
            if(c1 >= 2) {
                return true;
            }
        }
        
        return false;
    }
};```



