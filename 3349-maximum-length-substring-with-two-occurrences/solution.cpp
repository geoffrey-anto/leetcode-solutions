class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            unordered_map<char, int> mp;
            for(int j=i; j<n; j++) {
                mp[s[j]] += 1;
                
                bool f = false;
                
                for(auto &[k,v]: mp) {
                    if(v > 2) {
                        f = true;
                        break;
                    }
                }
                
                if(!f) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        
        return ans;

    }
};
