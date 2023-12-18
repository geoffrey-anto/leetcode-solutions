# Valid Anagram

## Leetcode Link: [Valid Anagram](https://leetcode.com/problems/valid-anagram/)
### Language: C++

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int arr[27];
        memset(arr, 0, sizeof(arr));
        for(auto &i:s) {
            arr[i-'a']++;
        }
        for(auto &i:t) {
            arr[i-'a']--;
        }

        for(auto &i:arr) {
            if(i!=0) {
                return false;
            }
        }
        return true;
     }
};```



