#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> getOrderedSet() {
  return tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>();
}

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        set<pair<int,int>> s;
        int n = nums.size();
        int ans = 0;        
        for(int i=0;i<n;i++) {
            auto it = s.upper_bound({nums[i],n});
            int ind = i;
            if(it!=s.begin()) {
                --it;
                ind = it->second;
                ans = max(ans,i-ind);                
            }
            s.insert({nums[i],ind});
        }
        return ans;
    }
};
