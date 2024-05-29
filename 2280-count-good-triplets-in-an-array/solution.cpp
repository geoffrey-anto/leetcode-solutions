#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int cnt = 0;
        int n = nums1.size();
        vector<long long> pre(n, 0), suff(n, 0);

        tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update> s;

        // 4,0,1,3,2
        // 4,1,0,2,3

        // take n1 and split it with the indexes in nums2

        // 1st) 3 at 4' in n2
        //   -> 3 at 3' in n1
        // save the count of nums before which are in nums1 in OS which are visited while
        // traversing through n2 i.e, because we are taking the ith element of nums2 and 
        // finding its position in n1 we only add elements in nums 2 before i' in OS

        // 4',0,1 | ,3,2
        // 4',1 | ,0,2,3

        // we get pre[idxMap1[nums2[1]]] as 1

        vector<long long> idxMap(n);

        for(int i=0; i<nums1.size(); i++) {
            idxMap[nums1[i]] = i;
        }                    

        for(int i=0; i<n; i++) {
            int backwardOfJ = s.order_of_key(idxMap[nums2[i]]);

            s.insert(idxMap[nums2[i]]);

            pre[i] = backwardOfJ;
        }

        tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update> s1;
        s.clear();

        for(int i=n-1; i>=0; i--) {
            int forwardOfJ = s.size() - s.order_of_key(idxMap[nums2[i]]);

            s.insert(idxMap[nums2[i]]);

            suff[i] = forwardOfJ;
        }

        long long ans = 0ll;

        for(int i=1; i<n-1; i++) {
            ans += (suff[i] * pre[i]);
        }

        return ans;
    }
};
