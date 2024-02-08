# Sliding Subarray Beauty

## Leetcode Link: [Sliding Subarray Beauty](https://leetcode.com/problems/sliding-subarray-beauty/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans(nums.size() - k + 1, 0);

        map<int, int> mp;

        for(int i=0; i<k; i++) {
            mp[nums[i]]++;
        }

        int cur = 0;

        for(auto& i: mp) {
            if(i.second + cur >= x) {
                ans[0] = i.first < 0 ? i.first : 0;
                break;
            } else {
                cur += i.second;
            }
        }

        for(int i=k; i<nums.size(); i++) {
            mp[nums[i-k]]--;
            mp[nums[i]]++;

            int c = 0;

            for(auto& v: mp) {
                if(v.second + c >= x) {
                    ans[i-k+1] = v.first < 0 ? v.first : 0;
                    break;
                } else {
                    c += v.second;
                }
            }
        }
        
        return ans;
    }
};```



