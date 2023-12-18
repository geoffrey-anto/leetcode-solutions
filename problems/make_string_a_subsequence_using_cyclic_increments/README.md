# Make String A Subsequence Using Cyclic Increments

## Leetcode Link: [Make String A Subsequence Using Cyclic Increments](https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/)
### Language: C++

```cpp
class Solution {
public:
    char getNextChar(char a) {
        int ascii = int(a);
        if(ascii == 122) {
            return 'a';
        }
        return char(ascii+1);
    }
    
    bool canMakeSubsequence(string str1, string str2) {
        if(str2.length() > str1.length()) {
            return false;
        }
        
        int cnt = 0;
        
        for(auto i: str1) {
            if(getNextChar(i) == str2[cnt] || i==str2[cnt]) {
                cnt++;
            }
        }
        
        if(cnt == str2.length()) return true;
        return false;
    }
};```



