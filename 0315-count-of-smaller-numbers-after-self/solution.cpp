#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set st;

        vector<int> counts(nums.size(), 0);

        int n = nums.size();

        for(int i=n-1; i>=0; i--) {
            int cnt = st.order_of_key(nums[i]);

            counts[i] = cnt;

            st.insert(nums[i]);
        }

        return counts;
    }
};
