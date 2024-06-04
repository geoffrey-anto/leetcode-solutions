class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for(auto i: s) {
            mp[i]++;
        }

        int ans = 0;

        int is1 = 0;

        for(auto &[k, v]: mp) {
            if(v % 2 != 0) {
                is1 = 1;
            } 

            ans += v / 2;
        }

        return (ans * 2) + is1;
    }
};
