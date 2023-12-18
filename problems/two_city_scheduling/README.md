# Two City Scheduling

## Leetcode Link: [Two City Scheduling](https://leetcode.com/problems/two-city-scheduling/)
### Language: C++

```cpp
class Solution {
public:
    
    static bool cmpr(vector<int> &a, vector<int> &b){
        return (a[0]-a[1])<(b[0]-b[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmpr);
        int c=0;
        int n=costs.size();
        for(int i=0;i<n/2;i++){
            c+=costs[i][0];
        }
        for(int i=n/2;i<n;i++){
            c+=costs[i][1];
        }
        return c;
    }
};```



