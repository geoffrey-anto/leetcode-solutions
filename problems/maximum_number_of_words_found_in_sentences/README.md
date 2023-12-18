# Maximum Number Of Words Found In Sentences

## Leetcode Link: [Maximum Number Of Words Found In Sentences](https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/)
### Language: C++

```cpp
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n=sentences.size();
        int mx;
        for(auto i:sentences){
            int c=0;
            for(char j:i){
                if(isspace(j)){
                    c++;
                }
            }
            mx=max(mx,c);
        }
        return mx+1;
    }
};```



