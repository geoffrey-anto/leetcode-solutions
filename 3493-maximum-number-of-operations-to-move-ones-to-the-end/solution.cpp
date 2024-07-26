class Solution {
public:
    int maxOperations(string s) {
        reverse(begin(s), end(s));

        // s: 1001101
        // s_rev: 1011001

        // s: 00111
        // s_rev: 11100

        // Reverse >> Compress zeros >> count prefix count of 0s before each one >> add the cnt to the answer

        int curr = 0;
        int ans = 0;

        string temp = "";

        for(int i=0; i<s.size(); i++) {
            if(temp.size() && temp.back() == '0' and s[i] == '0') {
                continue;
            } else {
                temp += s[i];
            }
        }

        for(auto i: temp) {
            if(i == '0') {
                curr++;
            } else {
                ans += (curr);
            }
        }

        return ans;
    }
};
