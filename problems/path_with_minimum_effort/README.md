# Path With Minimum Effort

## Leetcode Link: [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)
### Language: C++

```cpp


class Solution {
    vector<vector<int>> D = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>
        > q;

        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));


        efforts[0][0] = 0;

        q.push({0, {0, 0}});

        while(!q.empty()) {
            auto top = q.top();
            q.pop();

            int x = top.second.first;
            int y = top.second.second;

            int diff = top.first;

            if(x == n-1 and y == m-1) {
                return diff;
            }

            for(auto &d: D) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(isValid(nx, ny, n, m)) {
                    int currDiff = max(diff, abs(heights[nx][ny] - heights[x][y]));

                    if(currDiff < efforts[nx][ny]) {
                        efforts[nx][ny] = currDiff;
                        q.push({currDiff, {nx, ny}});
                        continue;
                    }
                }
            }
        }


        return efforts[n-1][m-1];
    }
};```



