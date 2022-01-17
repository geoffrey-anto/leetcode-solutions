class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int o = 0;
        for (char c : S) {
            if (c == '(' && o++ > 0) ans += c;
            if (c == ')' && o-- > 1) ans += c;
        }
        return ans;
    }
};
