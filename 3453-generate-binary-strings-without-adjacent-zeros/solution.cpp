class Solution {
public:
    void f(string s, vector<string> &ans, int n) {
        if(s.size() == n) {
            ans.push_back(s);
            return;
        }

        if(s.size() == 0) {
            f(s+"0", ans, n);
            f(s+"1", ans, n);
            return;
        }

        char last = s.back();

        if(last == '0') {
            f(s+"1", ans, n);
        } else {
            f(s+"0", ans, n);
            f(s+"1", ans, n);
        }

        return;
    }

    vector<string> validStrings(int n) {
        vector<string> s;
        f("", s, n);

        return s;
    }
};
