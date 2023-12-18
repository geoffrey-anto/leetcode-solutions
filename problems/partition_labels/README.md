# Partition Labels

## Leetcode Link: [Partition Labels](https://leetcode.com/problems/partition-labels/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mp;
        int n=s.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int a=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            int j=max(j,mp[c]);
            cout<<j<<endl;
            if(i==j){
                ans.push_back(i-a+1);
                a = i+1;
                    
            }
        }
        return ans;
    }
};```



