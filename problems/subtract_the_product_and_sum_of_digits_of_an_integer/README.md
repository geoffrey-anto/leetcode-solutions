# Subtract The Product And Sum Of Digits Of An Integer

## Leetcode Link: [Subtract The Product And Sum Of Digits Of An Integer](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)
### Language: C++

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sm=0;
        int pr=1;
        while(n){
            int r=n%10;
            sm+=r;
            pr*=r;
            n=n/10;
        }
        return pr-sm;
    }
};```



