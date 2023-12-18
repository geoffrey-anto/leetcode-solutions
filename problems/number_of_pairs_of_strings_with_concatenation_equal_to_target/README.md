# Number Of Pairs Of Strings With Concatenation Equal To Target

## Leetcode Link: [Number Of Pairs Of Strings With Concatenation Equal To Target](https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/)
### Language: C++

```cpp
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and nums[i]+nums[j] == target){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};```



