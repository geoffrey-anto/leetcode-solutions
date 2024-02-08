# Minimum Number Of Pushes To Type Word I

## Leetcode Link: [Minimum Number Of Pushes To Type Word I](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/)
### Language: C++

```cpp
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        
        if(n <= 8) {
            return n;
        } else {
            int ans = 0;
            
            if(n <= 16) {
                return (8) + (2 * (n - 8));
            } else if(n <= 24) {
                return 8 + (2 * 8) + (3 * (n - 16));
            } else {
                return 8 + (2 * 8) + (3 * 8) + (4 * (n - 24));
            }
        }
        
        return -1;
    }
};```



