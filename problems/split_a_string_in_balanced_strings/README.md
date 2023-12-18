# Split A String In Balanced Strings

## Leetcode Link: [Split A String In Balanced Strings](https://leetcode.com/problems/split-a-string-in-balanced-strings/)
### Language: C++

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt=0;
        int temp = 0;
        for(auto i:s){
            if(i=='L'){
                temp--;
            } else {
                temp++;
            }
            if(temp == 0){
                cnt++;
            }
        }
        return cnt;
    }
};```



