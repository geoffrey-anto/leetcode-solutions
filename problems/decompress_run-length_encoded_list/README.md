# Decompress Run Length Encoded List

## Leetcode Link: [Decompress Run Length Encoded List](https://leetcode.com/problems/decompress-run-length-encoded-list/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n/2;i++){
            int freq=nums[2*i];
            int val=nums[2*i+1];
            for(int i=0;i<freq;i++){
                ans.push_back(val);
            }
        }
        return ans;
    }
};```



