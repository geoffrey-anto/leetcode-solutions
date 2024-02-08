# Partition Array According To Given Pivot

## Leetcode Link: [Partition Array According To Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> n1;
        vector<int> n2;
        int cnt = 0;

        for(auto &i: nums) {
            if(i == pivot) {
                cnt++;
            } else if(i < pivot) {
                n1.push_back(i);
            } else {
                n2.push_back(i);
            }
        }

        while(cnt) {
            n1.push_back(pivot);
            cnt--;
        }

        n1.insert(n1.end(), n2.begin(), n2.end());

        return n1;
    }
};```



