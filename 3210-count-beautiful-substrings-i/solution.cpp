class Solution {
public:
    // int f(int i, string s, int v, int c, int k, int n) {
    //     if(i == n) {
            
    //     }
    // }
    int beautifulSubstrings(string s, int k) {
        int ans = 0;
        
        for(int i=0; i<s.size(); i++) {
            int v = 0;
            int c = 0;
            for(int j=i; j<s.size(); j++) {
                if(s[j] == 'a' or s[j] == 'e' or s[j]=='i' or s[j] == 'o' or s[j] == 'u') {
                    v++;
                } else {
                    c++;
                }

                if(c == v and (c*v)%k == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
