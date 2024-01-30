class Solution {
public:
    long f(int a, int b, char op){
        if(op == '+') return a + b;
        else if(op == '-') return a - b;
        else if(op == '*') return (long)a*b;
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            if(tokens[i].size() == 1 && tokens[i][0] < 48){
                string op = tokens[i];
                
                long x1 = st.top();
                st.pop();
                long x2 = st.top();
                st.pop();
                long resolvedAns = f(x2, x1 , op[0]);
                st.push(resolvedAns);
            } else {
                st.push(stol(tokens[i]));
            }
        }
        return st.top();
    }
};



