# Greatest Common Divisor Of Strings

## Leetcode Link: [Greatest Common Divisor Of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)
### Language: C++

```cpp
class Solution {
public:
    
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1)
            return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));

    }
};```



