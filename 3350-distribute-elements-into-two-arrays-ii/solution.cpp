#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using ll=long long;

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    orderedMultiset;

// TLE multiset lb = logn & distance = logn approx therefore total ~ n^2
// orderedMultiset ~ Policy based data structures
class Solution {
public:
    int greaterCount(orderedMultiset &arr, int k) {
        auto i = arr.order_of_key(k+1);

        return arr.size() - i;
    }

    vector<int> resultArray(vector<int>& nums) {
        orderedMultiset arr1;
        orderedMultiset arr2;
        // tha kevalamana problem TLE

        arr1.insert(nums[0]);
        arr2.insert(nums[1]);

        int n = nums.size();
        vector<int> ans1 = {nums[0]}, ans2 = {nums[1]};

        for(int i=2; i<n; i++) {
            int cnt1 = greaterCount(arr1, nums[i]);
            int cnt2 = greaterCount(arr2, nums[i]);

            if(cnt1 > cnt2) {
                arr1.insert(nums[i]);
                ans1.push_back(nums[i]);
            } else if(cnt1 < cnt2) {
                arr2.insert(nums[i]);
                ans2.push_back(nums[i]);
            } else if(cnt1 == cnt2) {
                if(arr1.size() < arr2.size()) {
                    arr1.insert(nums[i]);
                    ans1.push_back(nums[i]);
                } else if(arr1.size() > arr2.size()) {
                    arr2.insert(nums[i]);
                    ans2.push_back(nums[i]);
                } else {
                    arr1.insert(nums[i]);
                    ans1.push_back(nums[i]);
                }
            } else {
                arr1.insert(nums[i]);
                ans1.push_back(nums[i]);
            }
        }

        ans1.insert(end(ans1), begin(ans2), end(ans2));

        return ans1;
    }
};
