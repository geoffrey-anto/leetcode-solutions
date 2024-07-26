class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;

        for(auto i: s) {
            if(i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u') {
                cnt++;
            }
        }

        if(cnt == 0) {
            return false;
        }

        if(cnt % 2 != 0) {
            return true;
        }

        return true;
    }
};
