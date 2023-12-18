# Determine If A Cell Is Reachable At A Given Time

## Leetcode Link: [Determine If A Cell Is Reachable At A Given Time](https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/)
### Language: C++

```cpp
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        

        int xDiag = sx - fx;
        int yDiag = sy - fy;

        if (t == 1){
            if(sx == fx && sy == fy) {
                return false;
            }
        }

        int greaterDiagonal = abs(xDiag) > abs(yDiag) ? abs(xDiag) : abs(yDiag);
        // cout << abs(xDiag) << endl;
        if (greaterDiagonal > t) {

            return false;
        }
        return true;
    }
};```



