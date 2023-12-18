# Element Appearing More Than 25% In Sorted Array

## Leetcode Link: [Element Appearing More Than 25% In Sorted Array](https://leetcode.com/problems/element-appearing-more-than-25%-in-sorted-array/)
### Language: C++

```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        int qtr = n / 4;

        int curr = 0;
        int currEle = arr[curr];

        curr++;

        for (int i=1; i<n; i++) {

            if (currEle == arr[i]) {
                curr++;
            } else {
                curr = 1;
            }
            
            currEle = arr[i];

            if (curr > qtr) {
                return arr[i];
            }
        }

        return currEle;
    }
};```



