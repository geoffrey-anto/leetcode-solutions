# Queries On A Permutation With Key

## Leetcode Link: [Queries On A Permutation With Key](https://leetcode.com/problems/queries-on-a-permutation-with-key/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p(m);
        for(int i=1;i<=m;i++){
            p[i-1]=i;
        }
        vector<int> v;
        for(int i=0;i<queries.size();i++){
            int num=queries[i];
            int j=0;
            for(j=0;j<m;j++){
                if(p[j]==num){
                    break;
                }
            }
            v.push_back(j);
            int temp=p[j];
            p.erase(p.begin()+j);
            p.insert(p.begin(),temp);
        }
        return v;
    }
};```



