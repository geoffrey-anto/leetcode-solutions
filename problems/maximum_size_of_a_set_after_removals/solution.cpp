class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int c = 0;

        unordered_set<int> s1(begin(nums1), end(nums1));
        unordered_set<int> s2(begin(nums2), end(nums2));

        unordered_set<int> i;
        
        for(auto v: s1) {
            if(s2.find(v) != s2.end()) {
                i.insert(v);
            }
        }

        c = i.size();

        int n1 = min((int)(s1.size() - c), (int)(n / 2));
        int n2 = min((int)(s2.size() - c), (int)(n / 2));

        if((n1 + n2 + c) > n) {
            return n;
        } else {
            return (n1 + n2 + c);
        }
    }
};