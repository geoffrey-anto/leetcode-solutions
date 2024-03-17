class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt = 0;
        
        for(auto i: s) {
            if(i == c) {
                cnt++;
            }
        }
        
        return cnt * (cnt + 1ll)/2ll;
    }
};
