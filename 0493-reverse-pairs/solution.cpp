#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ll long long
#define ordered_set tree<long long, null_type,greater_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> 


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // multiset<int> st;
        ordered_set st;

        // for(auto i: nums) {
        //     st.insert(i);
        // }

        int ans = 0;

        for(auto i: nums) {
            int cnt = st.order_of_key((ll)i*2);

            ans += cnt;

            st.insert(i);
        }

        return ans;
    }
};
