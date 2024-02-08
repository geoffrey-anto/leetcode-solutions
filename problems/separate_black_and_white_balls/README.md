# Separate Black And White Balls

## Leetcode Link: [Separate Black And White Balls](https://leetcode.com/problems/separate-black-and-white-balls/)
### Language: C++

```cpp
class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;

        int n = s.size();

        vector<long long> cache(n, 0);
        
        long long currCnt = 0;

        for(int i=n-1; i>=0; i--) {
            if(s[i] == '0') {
                currCnt++;
            }

            cache[i] = currCnt;
        }

        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                ans += cache[i];
            }
        }

        return ans;
    }
};```



