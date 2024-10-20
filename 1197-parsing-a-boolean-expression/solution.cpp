class Solution {
public:
    bool parseBoolExpr(string exp ){
        stack<char> stk;
        for (char ch : exp) {
            if (ch == ',')
                continue;
            if (ch == ')') {
                bool t = false, f = false;
                while (stk.top() != '(') {
                    t |= stk.top() == 't';
                    f |= stk.top() == 'f';
                    stk.pop();
                }
                stk.pop();
                char op = stk.top();
                stk.pop();
                stk.push(op == '!'
                             ? (t ? 'f' : 't')
                             : (op == '&' ? (f ? 'f' : 't') : (t ? 't' : 'f')));
            } else
                stk.push(ch);
        }
        return stk.top() == 't';
    }
};
