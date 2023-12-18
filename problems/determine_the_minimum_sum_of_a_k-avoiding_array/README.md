# Determine The Minimum Sum Of A K Avoiding Array

## Leetcode Link: [Determine The Minimum Sum Of A K Avoiding Array](https://leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array/)
### Language: C++

```cpp
class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> ans;
        
        int i = 1;
        while(ans.size() < n) {
            if(ans.find(k-i) != ans.end()) {
                i++;
            } else {
                ans.insert(i);
                i++;
            }
        }
        int sum = 0;
        for(auto x: ans) {
            sum+=x;
        }
        return sum;
    }
};```



