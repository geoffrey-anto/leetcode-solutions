# Arranging Coins

## Leetcode Link: [Arranging Coins](https://leetcode.com/problems/arranging-coins/)
### Language: C++

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        long ans = n;
        return (sqrt(2*ans+0.25)-0.5);
    }
};```



