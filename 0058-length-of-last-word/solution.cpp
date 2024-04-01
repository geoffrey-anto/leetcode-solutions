class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(begin(s), end(s));
        int cnt = 0;
        bool flg = false;

        for(auto i: s) {
            if(i == ' ' and flg) {
                return cnt;
            }

            if(i != ' ') {
                cnt++;
                flg = true;
            }
        }

        return cnt;
    }
};
