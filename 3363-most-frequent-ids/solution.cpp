#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ll long long
#define ordered_set tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update> 

class Solution {
public:

    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<ll> ans;
        multiset<ll> m;

        // for(auto &i: nums) {
        //     m.insert(i);
        // }

        unordered_map<ll, ll> mp;

        // for(auto &i: nums) {
            // mp[i]++;
        // }

        for(int i=0; i<freq.size(); i++) {
            ll nFreq = mp[nums[i]];

            auto it = m.find(nFreq);

            if(it != m.end()) {
                m.erase(it);
            }

            if(freq[i] < 0) {
                mp[nums[i]] -= (ll)abs(freq[i]);
            } else {
                mp[nums[i]] += (ll)freq[i];
            }

            m.insert(mp[nums[i]]);

            // for(auto i: m) {
            //     cout << i << " ";
            // }
            // cout << endl;

            auto it2 = m.rbegin();

            if(it2 != m.rend()) {
                ans.push_back(*it2);
            } else {
                ans.push_back(0ll);
            }
        }

        return ans;
    }
};
