# Queries On Number Of Points Inside A Circle

## Leetcode Link: [Queries On Number Of Points Inside A Circle](https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans1;
        for(int i=0;i<queries.size();i++){
            vector<int> a=queries[i];
            int x,y,r;
            x=a[0];
            y=a[1];
            r=a[2];
            int ans=0;
            for(int j=0;j<points.size();j++){
                vector<int> b=points[j];
                if((((b[0]-x)*(b[0]-x))+((b[1]-y)*(b[1]-y)))<=r*r){
                    ans++;
                }
            }
            ans1.push_back(ans);
        }
        return ans1;
    }
};```



