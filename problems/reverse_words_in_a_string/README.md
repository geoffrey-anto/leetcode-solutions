# Reverse Words In A String

## Leetcode Link: [Reverse Words In A String](https://leetcode.com/problems/reverse-words-in-a-string/)
### Language: C++

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        int n = s.length();

        int st = 0;

        int ed = n-1;

        while(st < n && s[st] == ' ') {
            st++;
        }

        while(ed > 0 && s[ed] == ' ') {
            ed--;
        }

        int pt = ed + 1;

        string buffer = "";
        bool isPrevSpace = false;

        for(int i=st; i<=ed; i++) {
            if(s[i] == ' ') {
                if (isPrevSpace) {
                    continue;
                }
                ans = " " + buffer + ans;
                buffer = "";
                isPrevSpace=true;
            } else {
                isPrevSpace = false;
                buffer += s[i];
            }
        }

        return buffer + ans;
    }
};```



