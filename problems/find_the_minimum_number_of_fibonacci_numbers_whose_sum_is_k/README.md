# Find The Minimum Number Of Fibonacci Numbers Whose Sum Is K

## Leetcode Link: [Find The Minimum Number Of Fibonacci Numbers Whose Sum Is K](https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/)
### Language: C++

```cpp
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if(k==0){
            return 1;
        }
        vector<long> fib(47);
        fib[0]=0;
        fib[1]=0;
        fib[2]=1;
        for(int i=3;i<47;i++){
            fib[i]=fib[i-1]+fib[i-2];
        }
        int x=0;
        while(k>0){
            for(int i=46;i>=1;i--){
                if(fib[i]<=k){
                    k-=fib[i];
                    x++;
                    break;
                }
            }
        }
        return x;
    }
};```



