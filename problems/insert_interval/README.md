# Insert Interval

## Leetcode Link: [Insert Interval](https://leetcode.com/problems/insert-interval/)
### Language: C++

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // there can be 2 cases one the given interval is in a INT already present this case 
        // u will return the orginal array

        // else if not there we have to find a int to merge
        // if is is conflicting merger consicutive one together
        vector<vector<int>> ans;
        int pos = 0;

        int n = intervals.size();
        int i=0;
        for(i=0; i<n; i++) {
            if(intervals[i][1] >= newInterval[0]) {
                break;
            }
            ans.push_back(intervals[i]);
        }

        int left = newInterval[0];
        int right = newInterval[1];
        for(; i<n; i++) {
            if(intervals[i][0] > newInterval[1]) {
                break;
            }
            left = min(left, intervals[i][0]);
            right = max(right, intervals[i][1]);
        }

        ans.push_back({left, right});

        while(i<n) {
            ans.push_back(intervals[i]);
            i++;
        }

        cout << pos << endl;

        return ans;

    }
};```



