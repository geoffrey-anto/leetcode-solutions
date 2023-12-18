# Get Maximum In Generated Array

## Leetcode Link: [Get Maximum In Generated Array](https://leetcode.com/problems/get-maximum-in-generated-array/)
### Language: C++

```cpp
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n < 1) return 0;
        vector<int> num(n+1, 0);
        num[1] = 1;
//         
        int i = 1;
//         
        while((2 * i) <= n){
            num[2 * i] = num[i];
            if((2 * i) + 1 <= n)
                num[2 * i + 1] = num[i] + num[i + 1];
            i++;
        }
        return *max_element(num.begin(), num.end());
    }
};```



