# Number Of Steps To Reduce A Number To Zero

## Leetcode Link: [Number Of Steps To Reduce A Number To Zero](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/)
### Language: C++

```cpp
class Solution {
public:
    int n=0;
    int helper(int num){
        if( num == 0 ){
            return 0;
        }
        if( num%2 == 0 ){
            helper(num/2);
        } else {
            helper(num-1);
        }
        
        n++;
        return n;
    }
    
    int numberOfSteps(int num) {
        return helper(num);
    }
};```



