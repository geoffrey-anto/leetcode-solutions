class Solution {
public:
    string shortestPalindrome(string s) {
        string cpy = s;
        string r = s;
        reverse(begin(r), end(r));

        s = s + "#" + r;

        vector<int> v(s.size(), 0);

        int i = 1;
        int k = 0;

        while(i < s.size()) {
            if(s[i] == s[k]) {
                k++;
                v[i++] = k;
            } else {
                if(k > 0) {
                    k = v[k - 1];
                } else {
                    v[i] = 0;
                    i++;
                }
            }
        }

        auto temp = cpy.substr(v[s.size() - 1]);
        reverse(begin(temp), end(temp));

        return temp + cpy;
    }
};
