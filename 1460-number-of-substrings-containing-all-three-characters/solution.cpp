class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int prev = 0;
        int curr = 0;

        int ans = 0;

        // store freq of a b c
        vector<int> mp(3, 0);

        for(curr = 0; curr < n; curr++) {
            // INC count
            mp[s[curr] - 'a']++;

            // while there is atleast 1 pair of a b c
            // keep removing the read end
            while(mp[0]>0 and mp[1]>0 and mp[2]>0) {
                // if we have something like |abc|abb -> abc = 1 count, and we can include abb also
                // so making abc, abca, abcab, abcabb - therefore (n - curr) no of sub strs
                ans += (n - curr);
                mp[s[prev] - 'a']--;
                prev++;
            }
        }

        return ans;
    }
};
