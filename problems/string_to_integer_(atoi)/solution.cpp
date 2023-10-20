class Solution {
public:
    bool isValid(char c) {
        return (c >= '0' and c <= '9');
    } 
    int myAtoi(string s) {
        int ans = 0;
        int i = 0;
        int n = s.length();
        bool isNegative = false;
        while (s[i] == ' ') i++;

        if (s[i] == '-' or s[i] == '+') {
            isNegative = (s[i] == '-');
            i++;
        };

        while (i < n && isValid(s[i])) {
            int digit = s[i] - '0';

            if (ans > (INT_MAX-digit) / 10) {
                return isNegative ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
            i++;
        }

        return isNegative ? ans * -1 : ans;
    }
};