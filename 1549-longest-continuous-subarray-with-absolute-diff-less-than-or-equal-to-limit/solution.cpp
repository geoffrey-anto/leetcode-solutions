#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> getOrderedSet() {
  return tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>();
}


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        auto m = getOrderedSet<pair<int, int>>();

        int l = 0;

        int ans = 0;

        for(int r=0; r<n; r++) {
            m.insert({nums[r], r});

            int mx = (*m.begin()).first;
            int mn = (*m.rbegin()).first;

            while(abs(mx - mn) > limit) {
                m.erase({nums[l], l});

                l++;

                mx = (*m.begin()).first;
                mn = (*m.rbegin()).first;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
