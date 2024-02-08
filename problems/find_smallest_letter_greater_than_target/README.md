# Find Smallest Letter Greater Than Target

## Leetcode Link: [Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)
### Language: C++

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ub = upper_bound(begin(letters), end(letters), target);

        if(ub == end(letters)) {
            return letters[0];
        }

        return *ub;
    }
};```



