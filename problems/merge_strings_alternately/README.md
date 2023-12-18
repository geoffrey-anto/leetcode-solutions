# Merge Strings Alternately

## Leetcode Link: [Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/)
### Language: C++

```cpp
class Solution {
public:
    void merge(string s1,string s2,string &ans,int i1,int i2,bool b){
        if(i1>=s1.size() and i2>=s2.size()){
            return;
        }
        if((b and i1<s1.size())){
            ans=ans+s1[i1];
            merge(s1,s2,ans,i1+1,i2,!b);
        } else if((!b and i2<s2.size())) {
            ans=ans+s2[i2];
            merge(s1,s2,ans,i1,i2+1,!b);
        }
    }
    string mergeAlternately(string word1, string word2) {
        string ans="";
        merge(word1,word2,ans,0,0,true);
        if(word1.size()>word2.size()){
            ans += word1.substr(word2.size()+1,word1.size());
        } else if(word1.size()<word2.size()){
            ans += word2.substr(word1.size(),word2.size());
        }
        return ans;
    }
};```



