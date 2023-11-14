class Solution {
public:
    bool isValid(char c) {
        return (c >= '0' and c <= '9');
    } 

    int solve(string s, int n, int ans, bool isNegative, int ptr) {
        if(ptr >= n or !isValid(s[ptr])) {
            if(isNegative) {
                return ans * -1;
            } else {
                return ans;
            }
        }

        int digit = s[ptr] - '0';

        if(ans > (INT_MAX-digit) / 10) {
            return isNegative ? INT_MIN : INT_MAX;
        }

        return solve(s,  n, ans * 10 + digit, isNegative, ptr+1);
    }
    int myAtoi(string s) {
        int ptr = 0;

        return solve([&](string s) {
            while(s[ptr] == ' ') ptr++;
            return s;
        }(s),
        s.length(),
        0,
        [&](string s, int p){
            if(s[p] == '+' or s[p] == '-') {
                ptr++;
                return s[p] == '-';
            } else {
                return false;
            }
        }(s, ptr),
        ptr
        );
    }
};
