# The K Weakest Rows In A Matrix

## Leetcode Link: [The K Weakest Rows In A Matrix](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<mat.size();i++){
            int x=count(mat[i].begin(),mat[i].end(),1);
            q.push(make_pair(x,i));
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};```



