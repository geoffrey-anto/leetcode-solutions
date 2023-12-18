# Check If Two String Arrays Are Equivalent

## Leetcode Link: [Check If Two String Arrays Are Equivalent](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/)
### Language: C++

```cpp
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a;
        string b;
        for(auto i:word1){
            a=a+i;
        }
        for(auto i:word2){
            b=b+i;
        }
        return a==b;
    }
};```



