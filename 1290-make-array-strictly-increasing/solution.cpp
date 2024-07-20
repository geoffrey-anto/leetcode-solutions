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
    int f(int i, int prev, vector<int> &arr1, vector<int> &arr2, map<pair<int, int>, int> &dp) {
        if(i == arr1.size()) {
            return 0;
        }

        int j = 0;

        if(dp.find({i, prev}) != dp.end()) {
            return dp[{i, prev}];
        }

        int ans = 1e8;

        if(arr1[i] > prev) {
            ans = min(ans, f(i+1, arr1[i], arr1, arr2, dp));
        }

        // // try changing the curr index with the min possible in the 

        auto currLeastPossible = upper_bound(begin(arr2), end(arr2), prev);

        j = (int)(currLeastPossible - arr2.begin());

        if(j < arr2.size()) {
            ans = min(ans, 1 + f(i+1, arr2[j], arr1, arr2, dp));
        }

        return dp[{i, prev}] = ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2), end(arr2));

        // auto os = getOrderedSet<int>();

        // for(auto i: arr2) {
        //     os.insert(i);
        // }

        // vector<vector<int>> dp(arr1.size()+2, vector<int>(arr2.size()+1, -1));
        map<pair<int, int>, int> dp;

        int ans =  f(0, -1, arr1, arr2, dp);

        if(ans >= 1e8) {
            return -1;
        } else {
            return ans;
        }
    }
};
