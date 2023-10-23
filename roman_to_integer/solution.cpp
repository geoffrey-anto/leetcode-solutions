class Solution {
public:
    int romanToInt(string s) {
        int mp[27];
        int ans = 0;
        int n = s.length();

        mp['I' - 'A'] = 1;
        mp['V' - 'A'] = 5;
        mp['X' - 'A'] = 10;
        mp['L' - 'A'] = 50;
        mp['C' - 'A'] = 100;
        mp['D' - 'A'] = 500;
        mp['M' - 'A'] = 1000;

        for(auto i=0; i<n - 1; i++) {
            if (mp[s[i] - 'A'] < mp[s[i+1] - 'A']) {
                ans -= mp[s[i] - 'A'];
            } else {
                ans += mp[s[i] - 'A'];
            }
        }

        ans += mp[s[n-1] - 'A'];

        return ans;
    }
};