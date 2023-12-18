# Minimum Absolute Difference

## Leetcode Link: [Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/)
### Language: C++

```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> answer;
        int minPairDiff = INT_MAX;
        for (int i = 0; i < arr.size() - 1; ++i) {            
            int currPairDiff = arr[i + 1] - arr[i];
            if (currPairDiff == minPairDiff) {
                answer.push_back({arr[i], arr[i + 1]});           
            } else if (currPairDiff < minPairDiff) {
                answer = {};
                answer.push_back({arr[i], arr[i + 1]});
                minPairDiff = currPairDiff;
            }
        }
        return answer;
    }
};
```



