# Check If All Characters Have Equal Number Of Occurrences

## Leetcode Link: [Check If All Characters Have Equal Number Of Occurrences](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/)
### Language: C++

```cpp
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        bool flg=true;
        int prev=mp.begin()->second;
        for(auto pt:mp){
            if(prev != pt.second){
                flg=false;
            }
        }
        return flg;
    }
};```



