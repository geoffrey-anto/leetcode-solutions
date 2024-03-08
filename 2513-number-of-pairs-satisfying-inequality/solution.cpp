#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using ll=long long;

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    sortedList;

// IF ANY MATH EQN GIVEN LIKKE THIS PROB REARRANGE THE DAMN EQN
// SEPERATE IT INTO TO SEPARATE ITERABLE VALUES WITH CONSTANTS ON A SINGLE SIDE

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        sortedList s;

        int n = nums1.size();

        long long cnt = 0;

        for(int i=0; i<n; i++) {
            cnt += s.order_of_key(nums1[i] - nums2[i] + diff + 1);
            s.insert(nums1[i] - nums2[i]);
        }

        return cnt;
    }
};
