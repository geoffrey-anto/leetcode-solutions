# Find Words That Can Be Formed By Characters

## Leetcode Link: [Find Words That Can Be Formed By Characters](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/)
### Language: C++

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> map;
        for(auto i: chars) {
            map[i]++;
        }

        int ans = 0;
        
        for(auto &i: words) {
            auto temp = map;
            auto found = true;
            for(auto &ch: i) {
                if(temp.find(ch) == temp.end()) {
                    found = false;
                    break;
                }
                if(temp[ch] == 0) {
                    found = false;
                    break;
                }

                temp[ch]--;
            }

            if(found) ans+=i.size();
        }

        return ans;
    }
};```



