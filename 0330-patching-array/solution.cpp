#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> getOrderedSet() {
  return tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>();
}

template <typename T> void print(T arr) {
  for (auto i : arr) {
    cout << i << ' ';
  }
  cout << endl;
}

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        auto s = getOrderedSet<pair<long long, long long>>();
        long long key = 0;

        for(auto i: nums) {
            s.insert({i, key++});
        }

        auto getNextWhichIsNotPossibleToSumUp = [&s, &n, &key]() {
            long long sum = 1ll;

            for(auto i: s) {
                if(i.first > sum) {
                    break;
                }

                sum += i.first;
            }

            if(sum > n) {
                return false;
            }

            if(sum >= INT_MAX) {
                return false;
            }

            s.insert({sum, key++});

            return true;
        };

        int patchCount = 0;

        while(true) {
            auto wasSumObtainable = getNextWhichIsNotPossibleToSumUp();

            if(!wasSumObtainable) {
                break;
            }

            patchCount++;
        }

        return patchCount;
    }
};
