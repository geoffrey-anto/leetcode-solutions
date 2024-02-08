# Buy Two Chocolates

## Leetcode Link: [Buy Two Chocolates](https://leetcode.com/problems/buy-two-chocolates/)
### Language: C++

```cpp
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = INT_MAX, min2 = INT_MAX;

        for(auto &i: prices) {
            if(min1 >= i) {
                min2 = min1;
                min1 = i;
            } else {
                min2 = min(min2, i);
            }
        }

        if ((min1 + min2) > money) {
            return money;
        }
        return money - (min1 + min2);
    }
};```



