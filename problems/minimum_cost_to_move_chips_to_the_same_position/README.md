# Minimum Cost To Move Chips To The Same Position

## Leetcode Link: [Minimum Cost To Move Chips To The Same Position](https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/)
### Language: C++

```cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n=position.size();
        int e=0,o=0;
        for(int &pos:position){
            if(pos%2==0){
                e++;
            } else {
                o++;
            }
        }
        return min(e,o);
    }
};```



