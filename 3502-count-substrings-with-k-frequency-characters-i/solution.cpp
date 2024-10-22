class Solution {
public:
    int getNumSubarrays(string &s, int l, int r) {
        int n = s.size();

        int left = l - 0;

        if(left != 0) {
            left--;
        }

        int right = n - r - 1;

        return (left == 0 ? 1 : left) * (right == 0 ? 1 : right) + 1;
    }

    int numberOfSubstrings(string s, int k) {
        int l = 0;
        int r = 0;

        int ans = 0;

        for(auto i=0; i<s.size(); i++) {
            unordered_map<char, int> mp;
            for(auto j=i; j<s.size(); j++) {
                mp[s[j]]++;
                if(mp[s[j]] >= k) {
                    ans += (s.size() - j);
                    break;
                }
            }
        }


        return ans;
    }
};
