class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        bool f = false;

        for(auto i: s) {
            if(!f and i == '*') {
                ans++;
            }

            if(i == '|') {
                f = !f;
            }
        }

        return ans;
    }
};
