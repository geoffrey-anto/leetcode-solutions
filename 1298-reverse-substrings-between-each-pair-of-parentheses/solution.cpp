class Solution {
public:
    // string reverseParentheses(string s) {
    //     int l = 0;

    //     int n = s.size();

    //     int r = n - 1;

    //     while(l <= r) {
    //         while(l < n and s[l] != '(') {
    //             l++;
    //         }

    //         while(r >= 0 and s[r] != ')') {
    //             r--;
    //         }

    //         reverse(s.begin()+l, s.begin()+r+1);
    //         for(int i=l; i<r+1; i++) {
    //             if(s[i] == '(') {
    //                 s[i] = ')';
    //             } else if(s[i] == ')') {
    //                 s[i] = '(';
    //             }
    //         }
    //         l++;
    //         r--;
    //     }

    //     string ans = "";

    //     for(int i=0; i<n; i++) {
    //         if(s[i] != ')' and s[i] != '(') {
    //             ans += s[i];
    //         }
    //     }

    //     return ans;
    // }

    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> opened, pair(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                opened.push_back(i);
            if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string res;
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')')
                i = pair[i], d = -d;
            else
                res += s[i];
        }
        return res;
    }
};
