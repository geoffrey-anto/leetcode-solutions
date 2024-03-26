class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();

        int l = 0;

        int o = 0, c = 0;
        int ans = 0;


        while(l < n) {
            if(s[l] == '[') {
                o++;
            } else {
                c++;
            }
            if(c > o) {
                ans++;
                o++;
                c--;
            }

            l++;
        }

        return ans;
    }
};
