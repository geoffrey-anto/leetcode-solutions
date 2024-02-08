# Partitioning Into Minimum Number Of Deci Binary Numbers

## Leetcode Link: [Partitioning Into Minimum Number Of Deci Binary Numbers](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)
### Language: C++

```cpp
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};```



