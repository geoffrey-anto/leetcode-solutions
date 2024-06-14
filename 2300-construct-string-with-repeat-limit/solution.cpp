class Solution {
public:
    char getNextLargestOptimalCharacter(char &prev, int &take, int &limit, map<char, int, greater<char>> &mp) {
        char res = '-';

        for(auto &[k, v]: mp) {
            if(k == prev and take >= limit) {
                continue;
            } else {
                res = k;
                break;
            }
        }

        if(res == '-') {
            return res;
        }

        if(mp[res] == 1) {
            mp.erase(res);
        } else {
            mp[res]--;
        }

        if(res == prev) {
            take++;
        } else {
            take = 1;
        }

        return res;
    }
    string repeatLimitedString(string s, int repeatLimit) {
        string ans = "";

        char curr = '-';

        map<char, int, greater<char>> mp;

        for(auto &i: s) {
            mp[i]++;
        }

        int limit = repeatLimit;
        int take = 0;

        while(true) {
            curr = getNextLargestOptimalCharacter(curr, take, limit, mp);

            if(curr == '-') {
                break;
            }

            ans += curr;
        }

        return ans;
    }
};
