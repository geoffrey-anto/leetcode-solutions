class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;

        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        for(auto i: nums1) {
            mp[i]++;
        }

        set<int> ans;

        for(auto &i: nums2) {
            if(mp[i])
                ans.insert(i);
        }

        return vector<int>(begin(ans), end(ans));
    }
};
