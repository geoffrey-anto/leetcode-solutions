class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string pattern1 = "";
        int s1 = 0;
        
        string pattern2 = "";
        int s2 = 0;
        
        if(x > y) {
            pattern1 = "ab";
            s1 = x;
            
            pattern2 = "ba";
            s2 = y;
        } else {
            pattern1 = "ba";
            s1 = y;
            
            pattern2 = "ab";
            s2 = x;
        }
        
        vector<char> st;
        
        int res = 0;
        
        for (char ch : s) {
            if (ch == pattern1[1] && !st.empty() && st.back() == pattern1[0]) {
                res += s1;
                st.pop_back();
            } else {
                st.push_back(ch);
            }
        }
        
        
        vector<char> st1;
        
        for (char ch : st) {
            if (ch == pattern2[1] && !st1.empty() && st1.back() == pattern2[0]) {
                res += s2;
                st1.pop_back();
            } else {
                st1.push_back(ch);
            }
        }

        return res;
    }
};
