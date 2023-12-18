# Fizz Buzz

## Leetcode Link: [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)
### Language: C++

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int i=1;i<n+1;i++){
            if(i%3 ==0 and i%5==0){
                ans[i-1]="FizzBuzz";
                continue;
            }
            if(i%3==0){
                ans[i-1]="Fizz";
                continue;
            }
            if(i%5==0){
                ans[i-1]="Buzz";
                continue;
            }
            ans[i-1]=to_string(i);
        }
        return ans;
    }
};```



