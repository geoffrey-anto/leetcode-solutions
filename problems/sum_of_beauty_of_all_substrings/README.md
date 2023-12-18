# Sum Of Beauty Of All Substrings

## Leetcode Link: [Sum Of Beauty Of All Substrings](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> maxAndMin(unordered_map<char, int> &mp){
        int mx = 0, mn = INT_MAX;
        for (auto it : mp) {
            mx = max(mx, it.second);
            mn = min(mn, it.second);
        }
        return {mx, mn};      
    }
    int beautySum(string s) {
        int sum = 0;
        int n = s.length();        
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp.clear();
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                auto x = maxAndMin(mp);                

                sum += (x[0] - x[1]);
            }
        }
        return sum;
    }
};
```



