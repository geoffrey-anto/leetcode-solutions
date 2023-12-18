# Check If Word Equals Summation Of Two Words

## Leetcode Link: [Check If Word Equals Summation Of Two Words](https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/)
### Language: C++

```cpp
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int s1=0,s2=0,s=0;
        for(auto &i:firstWord){
            s1=s1*10+(i-'a');
        }
        for(auto &i:secondWord){
            s2=s2*10+(i-'a');
        }
        for(auto &i:targetWord){
            s=s*10+(i-'a');
        }
        return s1+s2==s;
        
    }
};```



