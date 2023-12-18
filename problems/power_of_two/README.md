# Power Of Two

## Leetcode Link: [Power Of Two](https://leetcode.com/problems/power-of-two/)
### Language: C++

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }
        return (ceil(log2(n)) == floor(log2(n)));
    }
};```



