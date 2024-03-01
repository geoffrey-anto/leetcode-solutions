class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(begin(s), end(s));
        int count = 0;
        for(auto i: s) {
            if(i == '1') {
                count++;
            }
        }

        int l = s.size();

        if(count == 0) {
            return s;
        }

        string ans = "";

        for(int i=0; i<count-1; i++) {
            ans += "1";
        }

        for(int j=0; j<l-count; j++) {
            ans += "0";
        }

        ans += "1";

        return ans;
    }
};
