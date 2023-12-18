# Unique Number Of Occurrences

## Leetcode Link: [Unique Number Of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/)
### Language: C++

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int a:arr){
            if(map.find(a)!=map.end()){
                map[a]++;
            } else {
                map.insert(make_pair(a,1));
            }
        }
        unordered_map<int, int> rep;
        for(auto i:map){
            if(rep.find(i.second)!=rep.end()){
                return false;
            } else {
                rep.insert(make_pair(i.second,-1));
            }
        }
        return true;
    }
};```



