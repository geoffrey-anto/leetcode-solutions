class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto &w: words) {
            int n = w.size();

            bool flag = true;

            for(int i=0; i<n; i++) {
                if(w[i] != w[n - i - 1]) {
                    flag = false;
                }
            }

            if(flag) {
                return w;
            }
        }

        return "";
    }
};
