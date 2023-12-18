# Check If A String Is An Acronym Of Words

## Leetcode Link: [Check If A String Is An Acronym Of Words](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/)
### Language: C++

```cpp
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(words.size() != s.length()) return false;
        int cnt = 0;
        for(auto &i: words) {
            if(s[cnt] != i[0]){
                return false;
            }
            cnt++;
        }
        return true;
    }
};```



