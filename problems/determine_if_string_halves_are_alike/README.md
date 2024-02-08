# Determine If String Halves Are Alike

## Leetcode Link: [Determine If String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/)
### Language: Python

```py
class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n=len(s)
        mid = int(n/2)
        l=('a','e','i','o','u','A','E','I','O','U')
        lc=0
        rc=0
        for i in list(l):
            lc+=s[:mid].count(i)
        for i in list(l):
            rc+=s[mid:].count(i)
        return lc==rc
            ```



# Determine If String Halves Are Alike

## Leetcode Link: [Determine If String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/)
### Language: C++

```cpp
class Solution {
private:
    bool isVovel(char x)
    {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o'
            || x == 'u' || x == 'A' || x == 'E' || x == 'I'
            || x == 'O' || x == 'U')
            return true;
        else
            return false;
    }
public:
    bool halvesAreAlike(string s) {
        int c1 = 0, c2 = 0;

        int n = s.size();

        for(int i=0; i<n/2; i++) {
            if(isVovel(s[i])) {
                c1++;
            }
        }

        for(int i=n/2; i<n; i++) {
            if(isVovel(s[i])) {
                c2++;
            }
        }

        return c1 == c2;
    }
};```



