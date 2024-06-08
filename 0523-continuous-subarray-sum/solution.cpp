#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        if(nums.size() == 1) {
            return false;
        }

        if(nums.size() == 0) {
            return false;
        }

        int n = nums.size();

        vector<int> preSum(n, 0);
        preSum[0] = nums[0];

        for(auto i=1; i<n; i++) {
            if(nums[i] == 0 and nums[i-1] == 0) {
                return true;
            }
            preSum[i] = nums[i] + preSum[i-1];
        }

        unordered_map<int, int> s;
        
        s[0] = -1;
        int x = 0;

        for(auto i: preSum) {
            int rem = i;

            if(k != 0) {
                rem = rem % k;
            }

            if(s.find(rem) != s.end()) {
                if(x - s[rem] >= 2) {
                    return true;
                }
                x++;
                continue;
            } 

            s[rem] = x;
            x++;
        }


        return false;
    }
};
